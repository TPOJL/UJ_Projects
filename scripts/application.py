import pygame
from const import *
from stringInput import String

class Application:
    def __init__(self, language_model_manager):
        pygame.init()
        pygame.display.set_caption('COVID-19 Information Assistant')
        self.screen = pygame.display.set_mode(display_size, pygame.RESIZABLE)

        self.language_model_manager = language_model_manager
        self.response = ""

        self.font = pygame.font.Font(None, input_box_height)
        self.input_string = String(self.font, visible_lines_count, input_box_height, input_box_width - width_eps)

        self.running = True
        self.showResult = False
        self.started_generate = False

    def start(self):
        while self.running:
            if not self.showResult:
                for event in pygame.event.get():
                    if event.type == pygame.QUIT:
                        self.running = False

                    if event.type == pygame.VIDEORESIZE:
                        self.screen = pygame.display.set_mode((event.w, event.h), pygame.RESIZABLE)
                        self.input_string.resize(event.w, event.h)

                    if event.type == pygame.KEYDOWN:
                        if event.key == pygame.K_BACKSPACE:
                            self.input_string.pop()

                        elif event.key == pygame.K_RETURN:
                            str = self.input_string.submit()
                            self.response = self.language_model_manager.generate_response(str)
                            self.showResult = True
                            self.started_generate = False

                        elif event.key == pygame.K_UP:
                            self.input_string.scroll_up()
                        elif event.key == pygame.K_DOWN:
                            self.input_string.scroll_down()

                        else:
                            self.input_string.add(event.unicode)

                    self.draw_parts()
            else:
                if not self.started_generate:
                    self.generate_response_continuously()
                    self.started_generate = True

                for event in pygame.event.get():
                    if event.type == pygame.QUIT:
                        self.running = False
                    if event.type == pygame.VIDEORESIZE:
                        self.screen = pygame.display.set_mode((event.w, event.h), pygame.RESIZABLE)
                        self.input_string.resize(event.w, event.h)
                    elif event.type == pygame.KEYDOWN:
                        if event.key == pygame.K_BACKSPACE:
                            self.showResult = False
                            self.started_generate = False
                            self.input_string.reset_line()
                        elif event.key == pygame.K_UP:
                            self.input_string.scroll_up()
                        elif event.key == pygame.K_DOWN:
                            self.input_string.scroll_down()

                    self.draw_parts()

        pygame.quit()

    def generate_response_continuously(self):
        for symbol in self.response:
            self.input_string.add(symbol)

            total_lines = len(self.input_string.lines)
            visible_lines = self.input_string.visible_lines_count
            if total_lines > visible_lines:
                self.input_string.scroll_index = total_lines - visible_lines

            self.draw_parts()
            pygame.display.flip()
            pygame.time.delay(10)

    def draw_parts(self):
        self.screen.fill(bg_color)

        if not self.showResult:
            self.draw_title()
        else:
            self.draw_answer()

        pygame.draw.rect(self.screen, input_box_color, self.input_string.input_box)
        pygame.draw.rect(self.screen, border_color, self.input_string.input_box, border_width)
        self.input_string.draw_input_box(self.screen)
        pygame.display.flip()

    def draw_title(self):
        window_width = self.screen.get_width()
        for i, text in enumerate(title_text):
            label_surface = self.font.render(text, True, text_color)
            x = (window_width - label_surface.get_width()) // 2
            self.screen.blit(label_surface, (x, 20 + i * 40))

    def draw_answer(self):
        window_width = self.screen.get_width()
        label_surface = self.font.render(answer_text[0], True, text_color)
        x = (window_width - label_surface.get_width()) // 2
        self.screen.blit(label_surface, (x, 20))