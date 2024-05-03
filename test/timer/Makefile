NAME =			sphere_de_lespace_infini

SRC =			main.c						\
			../../objects/timer/new.c			\
			../../objects/timer/delete.c			\
			../../objects/timer/refresh.c			\
			../../src/vector_ptr/new.c			\
			../../src/vector_ptr/get.c			\
			../../src/vector_ptr/push.c			\
			../../src/vector_ptr/resize.c			\

OBJS =			$(SRC:.c=.o)

INCLUDE =		-I../../include -Dbunny_malloc=malloc

CC =			gcc

FLAGS =			-W -Wall -Wextra -g

LDFLAGS =		$(c_version) -L./ $(c_version) -llapin -lstdc++ -lsfml-system

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
			rm -f *~ *.o *.c~ include/*.h~
fclean: clean
			rm -f $(NAME)
re: fclean all

tree: fclean
			tree
