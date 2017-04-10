# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/05 18:06:53 by akpenou           #+#    #+#              #
#    Updated: 2017/04/11 00:08:07 by akpenou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = array.c matrix.c parse_field.c parser.c error.c window.c main.c load_param.c mesh.c camera.c draw.c bmp.c

OBJ = $(SRC:.c=.o)

NAME = scop

CFLAGS = -Wall -Wextra -Werror -g

LIBS = -F/Library/Frameworks -framework SDL2 -framework OpenGL

INCLUDES = -I../includes -I ~/.brew/include

GLEW = ../includes/libGLEW.a -L/Users/akpenou/.brew/lib -lglew

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	echo "\033[1;32m COMPILATION SCOP\033[0m"
	gcc $(CFLAGS) $(OBJ) -o $(NAME) $(GLEW) $(LIBS)

%.o: %.c
	gcc $(CFLAGS) -c $< $(INCLUDES) -o $@ 

clean:
	echo "\033[1;31m" "DELETE FILES SCOP" "\033[0m"
	rm -f $(OBJ)

fclean: clean
	echo "\033[1;31m" "DELETE SCOP" "\033[0m"
	rm -f $(NAME)

re: fclean all

bin: all clean
