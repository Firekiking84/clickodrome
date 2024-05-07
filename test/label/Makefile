NAME =			sphere_de_lespace_infini

SRC =			main.c					\
			../../src/draw/blit.c			\
			../../src/draw/set_zpixel.c		\
			../../src/draw/set_pixel.c		\
			../../objects/label/new.c		\
			../../src/draw/letter.c			\
			../../src/draw/text.c			\
			../../src/draw/get_value.c		\
			../../src/draw/get_ratio.c		\
			../../src/draw/get_npos.c		\
			../../src/draw/clear_zbuffer.c		\
			../../objects/label/delete.c		\
			../../src/draw/draw_rectangle.c		\
			../../objects/label/display.c		\

OBJS =			$(SRC:.c=.o)

INCLUDE =		-I../../include

CC =			gcc

FLAGS =			-W -Wall -Wextra -g

LDFLAGS =		$(c_version) -L./ $(c_version) -llapin -lsfml-graphics  -lsfml-window -lsfml-system -lstdc++ -lm -lavcall -lsfml-audio -ldl -lpthread -lopencv_imgproc -lopencv_highgui -lopencv_objdetect -lopencv_video -lopencv_videoio -lopencv_core -lavcall        -lusb -ludev

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
