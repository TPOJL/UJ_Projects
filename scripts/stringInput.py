from const import *

class String:
    def __init__(self, font, visible_lines_count = 9, input_box_height=500, input_box_width = 600):
        self.user_text = ""
        self.lines = [""]
        self.scroll_index = 0
        self.visible_lines_count = visible_lines_count
        self.input_box_height = input_box_height
        self.input_box_width = input_box_width
        self.input_box = start_input_box.copy()
        self.font = font
        self.cursos_index = [0, 0]

    def add(self, char):
        # Handle newlines
        if char == '\n':
            self.lines.append("")
            self._adjust_for_new_line()
            return

        # Get current line
        current_line = self.lines[-1]
        test_line = current_line + char

        # Check if line fits
        if self.font.size(test_line)[0] <= self.input_box_width:
            self.lines[-1] = test_line
            return

        # Find last space to wrap at word boundary
        last_space = current_line.rfind(' ')
        if last_space != -1 and last_space > 0:
            # Wrap at word boundary
            wrapped_part = current_line[last_space + 1:] + char
            self.lines[-1] = current_line[:last_space]
            self.lines.append(wrapped_part)
            self._adjust_for_new_line()
        else:
            # Break at character boundary
            while self.font.size(test_line)[0] > self.input_box_width:
                # Move last character to new line
                last_char = test_line[-1]
                test_line = test_line[:-1]
                if not test_line:  # Handle case where single character doesn't fit
                    break

            self.lines[-1] = test_line
            self.lines.append(last_char)
            self._adjust_for_new_line()

    def _adjust_for_new_line(self):
        active_lines = min(len(self.lines), self.visible_lines_count)
        if self.input_box.height < self.input_box_height * active_lines:
            # Expand the input box
            self.input_box.height += self.input_box_height
        # Always scroll to show the new line
        self.scroll_index = max(0, len(self.lines) - self.visible_lines_count)

    def draw_input_box(self, screen):
        pygame.draw.rect(screen, input_box_color, self.input_box)

        # Draw scrollbar background
        scrollbar_rect = pygame.Rect(
            self.input_box.right - scrollbar_width,
            self.input_box.top,
            scrollbar_width,
            self.input_box.height
        )
        pygame.draw.rect(screen, scrollbar_color, scrollbar_rect)

        # Draw scroll handle
        if len(self.lines) > self.visible_lines_count:
            handle_height = max(20, self.input_box.height * self.visible_lines_count / len(self.lines))
            handle_pos = (self.scroll_index / (len(self.lines) - self.visible_lines_count)) * (
                        self.input_box.height - handle_height)

            handle_rect = pygame.Rect(
                self.input_box.right - scrollbar_width,
                self.input_box.top + handle_pos,
                scrollbar_width,
                handle_height
            )
            pygame.draw.rect(screen, scrollbar_handle_color, handle_rect, border_radius=5)

        # Draw text
        visible_lines = self.visible_range()
        for i, line in enumerate(visible_lines):
            text_surface = self.font.render(line, True, text_color)
            screen.blit(text_surface, (self.input_box.x + 10, self.input_box.y + 10 + i * self.input_box_height))

            # Draw cursor only on active line
            if self.scroll_index + i == len(self.lines) - 1:
                cursor_x = self.input_box.x + 10 + self.font.size(line)[0]
                cursor_height = self.input_box_height - 20
                pygame.draw.line(screen, text_color,
                                 (cursor_x, self.input_box.y + 15 + i * self.input_box_height),
                                 (cursor_x, self.input_box.y + 15 + i * self.input_box_height + cursor_height),
                                 2)

    def visible_range(self):
        start = self.scroll_index
        end = min(self.scroll_index + self.visible_lines_count, len(self.lines))
        return self.lines[start:end]

    def pop(self):
        if len(self.lines[-1]) > 0:
            self.lines[-1] = self.lines[-1][:-1]  
        elif len(self.lines) > 1:
            self.lines.pop()
            if len(self.lines) >= self.visible_lines_count:
                self.scroll_index -= 1
                return
            self.input_box.height -= input_box_height
        return

    def submit(self):
        result = "\n".join(self.lines)
        self.reset_line()
        return result

    def reset_line(self):
        self.scroll_index = 0
        self.lines = [""]
        self.input_box = start_input_box.copy()

    def lines_len(self):
        return len(self.lines) - self.scroll_index

    def scroll_up(self):
        if self.scroll_index > 0:
            self.scroll_index -= 1

    def scroll_down(self):
        max_scroll = max(0, len(self.lines) - self.visible_lines_count)
        if self.scroll_index < max_scroll:
            self.scroll_index += 1

    def resize(self, window_width, window_height):
        self.input_box.x = (window_width - self.input_box_width) // 2
        self.input_box.y = window_height // 3
