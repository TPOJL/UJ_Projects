import pygame

# Colors
text_color = (30, 30, 30)
bg_color = (245, 245, 245)
input_box_color = (220, 230, 240)
border_color = (180, 200, 220)
scrollbar_color = (150, 150, 180)
scrollbar_handle_color = (100, 100, 140)

# Sizes
width_eps = 50
input_box_width = 700
input_box_height = 50
visible_lines_count = 9
display_size = (850, 600)
border_width = 2
scrollbar_width = 10

# Text
title_text = ['COVID-19 Information Assistant', 'Type your question below']
answer_text = ['Answer (press backspace for new query):']

# Positions
title_text_coordinates = [(75, 30), (75, 70)]
answer_text_coordinates = [(75, 30)] 

# Input box with border
start_input_box = pygame.Rect(75, 100, input_box_width, input_box_height)