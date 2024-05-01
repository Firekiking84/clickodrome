NAME =			textbox

SRC =			main.c						\
			../../display/blit.c				\
			../../display/draw_rectangle.c			\
			../../display/get_npos.c			\
			../../display/get_ratio.c			\
			../../display/get_value.c			\
			../../display/set_pixel.c			\
			../../display/set_zpixel.c			\
			../../src/mult_arrondi.c			\
			../../textbox/check_mouse_button.c		\
			../../textbox/copy_selection.c			\
			../../textbox/cut_selection.c			\
			../../textbox/delete_text_box.c			\
			../../textbox/display.c				\
			../../textbox/draw_bg.c				\
			../../textbox/draw_cursor.c			\
			../../textbox/draw_selected_area.c		\
			../../textbox/erase_selection.c			\
			../../textbox/event.c				\
			../../textbox/get_cursor_pos.c			\
			../../textbox/manage_control_key.c		\
			../../textbox/manage_key_event.c		\
			../../textbox/manage_mouse_button_event.c	\
			../../textbox/manage_shift_key.c		\
			../../textbox/manage_solo_key.c			\
			../../textbox/manage_text_event.c		\
			../../textbox/new.c				\
			../../textbox/paste.c				\
			../../string/append_str.c			\
			../../string/append_string.c			\
			../../string/clear.c				\
			../../string/compare.c				\
			../../string/compare_str.c			\
			../../string/delete.c				\
			../../string/erase.c				\
			../../string/get_char.c				\
			../../string/get_content.c			\
			../../string/get_len.c				\
			../../string/insert.c				\
			../../string/new.c				\
			../../string/new_str.c				\
			../../string/new_string.c			\
			../../string/pop_back.c				\
			../../string/push_back.c			\
			../../string/shrink_to_fit.c			\
			../../vector/clear.c				\
			../../vector/delete.c				\
			../../vector/new.c				\
			../../vector/new_vector.c			\
			../../vector/pop.c				\
			../../vector/push.c				\
			../../vector/pop_index.c			\
			../../vector/view.c				\
			../../vector/memcpy.c				\


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
