NAME		= scop

LIBS		= -L/Users/bal-khan/glfw/src -lglfw3
CFLG		= -Wextra -Wall -Werror -fsanitize=address -g

FILES		=	main.c\
			 	parse_file.c\
			 	shaders.c\
			 	read_file.c\
			 	quaternions.c\
			 	quaternions2.c\
			 	make_faces.c\
				ft_ascii.c\
				ft_ascii2.c\
				read_float.c\
				lst.c\
				lst2.c\
				state_start.c\
				state_line1.c\
				state_line2.c\
				state_line3.c\
				state_var1.c\
				state_var2.c\
				get_line1.c\
				get_line2.c\
				get_line3.c\
				get_var.c\
				sum_indexes.c\
				assign.c\
				die.c\
				draw.c\
				time.c\
				init_quats.c\
				bmp_reader.c\
				create_texture.c

PARSD		= parser/
SRCD		= srcs/
OBJD		= objs/
FRAMEWORKS	= -framework OpenGL -framework Appkit -framework Cocoa -framework IOKit -framework CoreVideo
INCLUDES	= -L/Users/bal-khan/glfw/src -lglfw3 
INCD		= includes/
HEADERS		= scop.h

OBJS		= $(addprefix $(OBJD), ${FILES:.c=.o})

all : $(NAME)

$(NAME) : $(OBJD) $(OBJS)
	gcc -o $@ $(OBJS) $(CFLG) $(INCLUDES) $(FRAMEWORKS)

$(OBJD)%.o: $(SRCD)%.c
	gcc -c $< -o $@ $(CFLG) -I $(INCD)

$(OBJD):
	mkdir -p $@

clean:
		rm -f $(OBJS)
		rm -rf $(OBJD)

fclean: clean
		rm -f $(NAME)

re: fclean all
