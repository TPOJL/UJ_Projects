import json
import os
import torch
import string
import nltk
from model import EncoderDecoder
from nltk.tokenize import word_tokenize

class ModelManager():
    def __init__(self) -> None:
        self.load_vocabular()
        self.load_model()
        self.model.load(self.word2ind, self.ind2word)

    def load_vocabular(self):
        self.word2ind = {}
        self.ind2word = {}
        with open('json_data/word2ind.json', 'r') as f:
            self.word2ind = json.load(f)
            print('Word 2 index was loaded')

        with open('json_data/ind2word.json', 'r') as f:
            self.ind2word = json.load(f)
            print('Index 2 word was loaded')

        self.word2ind = {key: int(value) for (key, value) in self.word2ind.items()}
        self.ind2word = {int(key): value for (key, value) in self.ind2word.items()}

    def load_model(self):
        self.model = EncoderDecoder(16848, 256, 64, max_answer_length=128, teaching_forcing=0.8) 
        if os.path.exists('model/model_weights.pth'):
            self.model.load_state_dict(torch.load('model/model_weights.pth', weights_only=True))
            print("Model was loaded")
        else:
            print("Model wasn't found")
        self.model.eval()

    def generate_response(self, input_str):
        token_ids = self.string_preproc(input_str).unsqueeze(0)
        device = next(self.model.parameters()).device

        with torch.no_grad():
            generated_ids = self.model(token_ids.to(device), device=device)

        tokens = generated_ids.squeeze(0).tolist()
        words = [self.ind2word[idx] for idx in tokens]

        return self.data_postproc(' '.join(words))

    def data_postproc(self, text):
        signs = set('\'()[].,?!:;')
        result = []
        capitalize_next = True

        for word in text.split():
            if word in {'<bos>', '<eos>', '<unk>'}:
                continue

            if word in signs:
                if result and result[-1][-1] == ' ':
                    result[-1] = result[-1][:-1] + word
                else:
                    result.append(word)

                if word in {'.', '!', '?'}:
                    capitalize_next = True
            else:
                if capitalize_next:
                    word = word.capitalize()
                    capitalize_next = False
                result.append(word)

        return ' '.join(result).replace(' .', '.').replace(' ?', '?').replace(' !', '!').replace(' )', ')').replace('( ', '(').replace(' ,', ', ')

    def string_preproc(self, text, max_len=256):

        if not text.strip():
            text = "empty query"

        text = text.lower().translate(
            str.maketrans('', '', string.punctuation))

        tokens = [
            self.word2ind.get(word, self.word2ind['<unk>'])
            for word in word_tokenize(text)
        ]

        tokens = [self.word2ind['<bos>']] + tokens + [self.word2ind['<eos>']]

        if len(tokens) < max_len:
            tokens += [self.word2ind['<pad>']] * (max_len - len(tokens))
        else:
            tokens = tokens[:max_len - 1] + [self.word2ind['<eos>']]

        return torch.LongTensor(tokens)
