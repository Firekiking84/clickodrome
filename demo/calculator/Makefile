NAME =			Clickodrome

SRC =			*.c				\
			$(wildcard ../../objects/*/*.c)	\
			$(wildcard ../../src/*/*.c)	\

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

tree: fclean
			tree
