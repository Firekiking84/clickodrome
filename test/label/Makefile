NAME =			sphere_de_lespace_infini

SRC =			main.c				\
			blit.c				\
			text.c				\
			set_zpixel.c			\
			set_pixel.c			\
			new_label.c			\
			loop_function.c			\
			letter.c			\
			get_value.c			\
			get_ratio.c			\
			get_npos.c			\
			clear_zbuffer.c			\
			delete_label.c			\
			display_function.c		\
			draw_rectangle.c		\
			display_label.c			\

OBJS =			$(SRC:.c=.o)

INCLUDE =		-I./include

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
