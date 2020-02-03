# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jandre-d <jandre-d@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/06/30 16:27:38 by jandre-d       #+#    #+#                 #
#    Updated: 2019/07/09 16:52:56 by jandre-d      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

FILES = dda draw main mlx_image player_input texture load_map error
C_FILES = $(FILES:=.c)
O_FILES = $(FILES:=.o)

$(NAME):
	cd minilibx_macos && make
	cd libft && make
	gcc $(C_FILES) -lmlx -framework OpenGl -framework AppKit \
		-L minilibx_macos/ -I libft/includes libft/libft.a \
			-o $(NAME) -Wall -Werror -Wextra

clean:
	cd minilibx_macos && make clean
	cd libft && make clean
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)
	cd libft && make fclean

re: fclean all

all: $(NAME)
