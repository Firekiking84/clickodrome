NAME =			Clickodrome

SRC =			$(shell find ./ -name "src/vector_ptr/*.c") \
			$(shell find ./ -name "objects/div/*.c")

OBJS =			$(SRC:.c=.o)

INCLUDE =		-I./include # -Dchar=float

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
			rm -f $(shell find ./ -name "*#")
			rm -f $(shell find ./ -name "*#")
fclean: clean
			rm -f $(NAME)
re: fclean all

test: fclean
			cd test/vector_test/ ; make report
			cd test/draw/ ; make report
			cd test/gui_test/ ; make report

tree: fclean
			tree
