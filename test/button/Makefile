NAME =			test_button

SRC =			main.c					\
			../../objects/button/new.c		\
			../../objects/button/delete.c   	\
			../../objects/button/event.c	        \
			../../objects/button/display.c		\
			../../src/vector_ptr/new.c		\
			../../src/vector_ptr/push.c		\
			../../src/vector_ptr/pop_back.c		\
			../../src/vector_ptr/erase.c		\
			../../src/vector_ptr/delete.c		\
			../../src/vector_ptr/resize.c		\
			../../src/draw/draw_rectangle.c		\
			../../src/draw/text.c			\
			../../src/draw/letter.c			\
			../../src/draw/set_pixel.c		\
			../../src/draw/set_zpixel.c		\
			../../src/draw/get_ratio.c		\
			../../src/draw/get_value.c		\
			../../src/draw/blit.c			\
			../../src/draw/get_npos.c		\


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
