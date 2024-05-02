NAME =			textbox

SRC =			main.c							\
			../../src/draw/blit.c					\
			../../src/draw/draw_rectangle.c				\
			../../src/draw/get_npos.c				\
			../../src/draw/get_ratio.c				\
			../../src/draw/get_value.c				\
			../../src/draw/set_pixel.c				\
			../../src/draw/set_zpixel.c				\
			../../objects/textbox/mult_arrondi.c			\
			../../objects/textbox/check_mouse_button.c		\
			../../objects/textbox/copy_selection.c			\
			../../objects/textbox/cut_selection.c			\
			../../objects/textbox/delete_text_box.c			\
			../../objects/textbox/display.c				\
			../../objects/textbox/draw_bg.c				\
			../../objects/textbox/draw_cursor.c			\
			../../objects/textbox/draw_selected_area.c		\
			../../objects/textbox/erase_selection.c			\
			../../objects/textbox/event.c				\
			../../objects/textbox/get_cursor_pos.c			\
			../../objects/textbox/manage_control_key.c		\
			../../objects/textbox/manage_key_event.c		\
			../../objects/textbox/manage_mouse_button_event.c	\
			../../objects/textbox/manage_shift_key.c		\
			../../objects/textbox/manage_solo_key.c			\
			../../objects/textbox/manage_text_event.c		\
			../../objects/textbox/new.c				\
			../../objects/textbox/paste.c				\
			../../src/string/append_str.c				\
			../../src/string/append_string.c			\
			../../src/string/clear.c				\
			../../src/string/compare.c				\
			../../src/string/compare_str.c				\
			../../src/string/delete.c				\
			../../src/string/erase.c				\
			../../src/string/get_char.c				\
			../../src/string/get_content.c				\
			../../src/string/get_len.c				\
			../../src/string/insert.c				\
			../../src/string/new.c					\
			../../src/string/new_str.c				\
			../../src/string/new_string.c				\
			../../src/string/pop_back.c				\
			../../src/string/push_back.c				\
			../../src/string/resize.c				\
			../../src/string/shrink_to_fit.c			\
			../../src/vector_ptr/clear.c				\
			../../src/vector_ptr/delete.c				\
			../../src/vector_ptr/erase.c				\
			../../src/vector_ptr/get.c				\
			../../src/vector_ptr/new.c				\
			../../src/vector_ptr/pop_back.c				\
			../../src/vector_ptr/push.c				\
			../../src/vector_ptr/resize.c				\

OBJS =			$(SRC:.c=.o)

INCLUDE =		-I./../../include

CC =			gcc

FLAGS =			-Wall -Wextra -g

LDFLAGS =		-L./ -llapin -lsfml-graphics -lsfml-audio -lsfml-window         \
                        -lsfml-system -lstdc++ -lm -ldl -lpthread                       \
                        -lopencv_imgproc -lopencv_highgui                               \
                        -lopencv_objdetect -lopencv_videoio                             \
                        -lopencv_core -lavcall                                          \

all:$(NAME)

$(NAME):$(OBJS)
			$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)
.c.o:
			$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@
ar:$(OBJS)
			ar rc $(NAME).a $(OBJS)
g:
			gdb --arg ./$(NAME)
clean:
			rm -f $(OBJS)
fclean: clean
			rm -f $(NAME)
re: fclean all

report: fclean all
			./$(NAME)
			gcov $(SRC)
			rm -f *.gcov

tree: fclean
			tree
