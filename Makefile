NAME =			Clickodrome

SRC =			display/main.c				\
			display/blit.c				\
			display/delete_label.c			\
			display/display_label.c			\
			display/draw_rectangle.c		\
			display/get_npos.c			\
			display/get_ratio.c			\
			display/get_value.c			\
			display/letter.c			\
			display/new_label.c			\
			display/text.c				\
			display/set_pixel.c			\
			display/set_zpixel.c			\
			display/loop_function.c			\
			display/display_function.c		\
			src/new_timer.c				\
			src/refresh_timer.c			\
			src/delete_timer.c			\

OBJS =			$(SRC:.c=.o)

INCLUDE =		-I./include -Dchar=float

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
			rm -f $(shell find ./ -name "*.o")
			rm -f $(shell find ./ -name "*~")
			rm -f $(shell find ./ -name "*.gcda")
			rm -f $(shell find ./ -name "*.gcno")
fclean: clean
			rm -f $(NAME)
re: fclean all

test: fclean
			cd test/vector_test/ ; make report
			cd test/draw/ ; make report

tree: fclean
			tree
