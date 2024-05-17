NAME =			Clickodrome

LIB1_NAME =		edit_note.so

LIB2_NAME =		refresh_time.so

SRC =			main.c					\
			$(wildcard ../../objects/*/*.c)		\
			$(wildcard ../../src/*/*.c)		\

LIB1_SRC =		edit_note.c				\

LIB2_SRC =		refresh_time.c				\


OBJS =			$(SRC:.c=.o)

LIB1_OBJS =		$(LIB1_SRC:.c=.o)
LIB2_OBJS =		$(LIB2_SRC:.c=.o)

INCLUDE =		-I./../../include

CC =			bcc

FLAGS =			-Wall -Wextra -g -ggdb

LDFLAGS =		-L./ -rdynamic

all:$(NAME) lib

lib:$(LIB1_NAME) $(LIB2_NAME)
lib_exe:
			$(CC) $(LIB_OBJS) -O0 $(LDFLAGS)
$(LIB1_NAME):$(LIB1_OBJS)
			$(CC) --shared -o $(LIB1_NAME) $(LIB1_OBJS) -O0 $(LDFLAGS)
$(LIB2_NAME):$(LIB2_OBJS)
			$(CC) --shared -o $(LIB2_NAME) $(LIB2_OBJS) -O0 $(LDFLAGS)
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
			rm -f $(LIB1_NAME)
			rm -f $(LIB2_NAME)
re: fclean all

test: fclean
			cd test/vector_test/ ; make report
			cd test/draw/ ; make report

tree: fclean
			tree
