NAME =			Clickodrome

SRC =			vector/main.c			\
			vector/clear.c			\
			vector/delete.c			\
			vector/new.c			\
			vector/pop.c			\
			vector/push.c			\
			vector/view.c			\
			vector/memcpy.c			\
			vector/pop_index.c		\

OBJS =			$(SRC:.c=.o)

INCLUDE =		-I./include

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
