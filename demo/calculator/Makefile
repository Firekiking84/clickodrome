NAME =			Clickodrome

LIB_NAME =		calculator.so

SRC =			main.c					\
			$(wildcard ../../objects/*/*.c)		\
			$(wildcard ../../src/*/*.c)		\

LIB_SRC =		add.c					\
			clear.c					\
			del.c					\
			divide.c				\
			init.c					\
			modulo.c				\
			multiply.c				\
			operation.c				\
			push_0.c				\
			push_1.c				\
			push_2.c				\
			push_3.c				\
			push_4.c				\
			push_5.c				\
			push_6.c				\
			push_7.c				\
			push_8.c				\
			push_9.c				\
			substract.c				\
			update_string.c				\
			$(wildcard ../../src/string/*.c)	\


OBJS =			$(SRC:.c=.o)

LIB_OBJS =		$(LIB_SRC:.c=.o)

INCLUDE =		-I./../../include

CC =			bcc

FLAGS =			-Wall -Wextra -g -ggdb

LDFLAGS =		-L./

all:$(NAME) lib

lib:$(LIB_NAME)

$(LIB_NAME):$(LIB_OBJS)
			$(CC) --shared -o $(LIB_NAME) $(LIB_OBJS) -O0 $(LDFLAGS)
$(NAME):$(OBJS)
			$(CC) $(OBJS) -O0 --coverage $(LDFLAGS) -o $(NAME)
.c.o:
			$(CC) $(FLAGS) -O0 $(INCLUDE) -c $< -o $@
ar:$(OBJS)
			ar rc $(NAME).a $(OBJS)
g:
			gdb --arg ./$(NAME)
clean:
			rm -f $(shell find ../../ -name "*.o")
			rm -f $(shell find ../../ -name "*~")
			rm -f $(shell find ../../ -name "*.gcda")
			rm -f $(shell find ../../ -name "*.gcno")
			rm -f $(shell find ../../ -name "*#")
			rm -f $(shell find ../../ -name "*#")
fclean: clean
			rm -f $(NAME)
			rm -f $(LIB_NAME)
re: fclean all

test: fclean
			cd test/vector_test/ ; make report
			cd test/draw/ ; make report

tree: fclean
			tree
