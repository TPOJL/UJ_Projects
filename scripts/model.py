import torch.nn as nn # type: ignore
import torch # type: ignore
import random

class EncoderDecoder(nn.Module):
    def __init__(self, vocab_len, hidden_dim, input_size, max_answer_length, teaching_forcing=1.0):
        super(EncoderDecoder, self).__init__()
        self.vocab_len = vocab_len
        self.hidden_dim = hidden_dim
        self.input_size = input_size
        self.teaching_forcing = teaching_forcing
        self.max_answer_length = max_answer_length
        self.word2ind = {}
        self.ind2word = {}

        self.encoder_embedding = nn.Embedding(vocab_len, input_size, padding_idx=self.word2ind.get('<pad>', 0))
        self.encoder_LSTM = nn.LSTM(
            input_size=self.input_size,
            hidden_size=self.hidden_dim,
            num_layers=2,
            batch_first=True,
            dropout=0.2
        )

        self.decoder_embedding = nn.Embedding(vocab_len, hidden_dim, padding_idx=self.word2ind.get('<pad>', 0))
        self.decoder_LSTM = nn.LSTM(
            input_size=self.hidden_dim,
            hidden_size=self.hidden_dim,
            num_layers=2,
            batch_first=True,
            dropout=0.2
        )

        self.decoder_prediction = nn.Sequential(
            nn.Linear(hidden_dim, vocab_len)
        )
    
    def load(self, word2ind, ind2word):
        self.word2ind = word2ind
        self.ind2word = ind2word

    def forward(self, x, device='cpu'):
        batch_size = x.size(0)

        input_emb = self.encoder_embedding(x)
        _, hidden_state = self.encoder_LSTM(input_emb)

        current_token = torch.full((batch_size, 1), self.word2ind['<bos>'], device=device)

        output_tokens = []

        for _ in range(self.max_answer_length):
            token_emb = self.decoder_embedding(current_token)

            lstm_out, hidden_state = self.decoder_LSTM(token_emb, hidden_state)

            logits = self.decoder_prediction(lstm_out)

            next_token = logits.argmax(dim=-1)  # [batch_size, 1]

            if next_token.item() == self.word2ind['<eos>']:
                break

            output_tokens.append(next_token)
            current_token = next_token

        if output_tokens:
            return torch.cat(output_tokens, dim=1)  # [batch_size, seq_len]
        else:
            return torch.empty((batch_size, 0), device=device)