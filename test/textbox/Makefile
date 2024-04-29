NAME =			textbox

SRC =			main.c				\
			../../display/blit.c		\
			../../display/draw_rectangle.c	\
			../../display/get_npos.c	\
			../../display/get_ratio.c	\
			../../display/get_value.c	\
			../../display/set_pixel.c	\
			../../display/set_zpixel.c	\
			../../textbox/delete_text_box.c	\
			../../textbox/display.c		\
			../../textbox/event.c		\
			../../textbox/new.c		\
			../../string/append_str.c	\
			../../string/append_string.c	\
			../../string/clear.c		\
			../../string/compare.c		\
			../../string/compare_str.c	\
			../../string/delete.c		\
			../../string/erase.c		\
			../../string/get_char.c		\
			../../string/get_content.c	\
			../../string/get_len.c		\
			../../string/new.c		\
			../../string/new_str.c		\
			../../string/new_string.c	\
			../../string/pop_back.c		\
			../../string/push_back.c	\
			../../string/shrink_to_fit.c	\
			../../vector/clear.c		\
			../../vector/delete.c		\
			../../vector/new.c		\
			../../vector/pop.c		\
			../../vector/push.c		\
			../../vector/pop_index.c	\
			../../vector/view.c		\
			../../vector/memcpy.c		\



OBJS =			$(SRC:.c=.o)

INCLUDE =		-I./../../include

CC =			bcc

FLAGS =			-Wall -Wextra -g

LDFLAGS =		-L./

all:$(NAME)

$(NAME):$(OBJS)
			$(CC) $(OBJS) -O0 --coverage $(LDFLAGS) -o $(NAME)
.c.o:
			$(CC) $(FLAGS) -O0 --coverage $(INCLUDE) -c $< -o $@
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
