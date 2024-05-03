NAME =			draw

SRC =			main.c					\
			../../display/blit.c			\
			../../display/draw_rectangle.c		\
			../../display/clear_pixelarray.c	\
			../../display/get_npos.c		\
			../../display/get_ratio.c		\
			../../display/get_value.c		\
			../../display/set_zpixel.c		\

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
