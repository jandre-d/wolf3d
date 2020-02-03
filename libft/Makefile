# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jandre-d <jandre-d@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/09 10:02:55 by jandre-d       #+#    #+#                 #
#    Updated: 2019/07/09 14:06:33 by jandre-d      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

DIR_SRC = src/
DIR_INCLUDES = includes/

# START LIBFT_BASE:

DIR_LIBFT_BASE = \
	$(addprefix $(DIR_SRC), libft_base/)

FILES_LIBFT_BASE = \
	ft_atoi ft_bzero ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_islower \
	ft_isprint ft_isupper ft_itoa ft_lstadd ft_lstdel ft_lstdelone \
	ft_lstiter ft_lstmap ft_lstnew ft_map ft_memalloc ft_memccpy ft_memchr \
	ft_memcmp ft_memcpy ft_memdel ft_memmove ft_memset ft_putchar \
	ft_putchar_fd ft_putendl ft_putendl_fd ft_putnbr ft_putnbr_fd ft_putstr \
	ft_putstr_fd ft_strcat ft_strchr ft_strclr ft_strcmp ft_strcpy ft_strdel \
	ft_strdup ft_strequ ft_strislower ft_strisupper ft_striter ft_striteri \
	ft_strjoin ft_strlcat ft_strlen ft_strlower ft_strmap ft_strmapi \
	ft_strncat ft_strncmp ft_strncpy ft_strnequ ft_strnew ft_strnstr \
	ft_strrchr ft_strrev ft_strsplit ft_strstr ft_strsub ft_strtrim \
	ft_strupper ft_tolower ft_toupper

C_FILES_LIBFT_BASE = \
	$(addprefix $(DIR_LIBFT_BASE), $(FILES_LIBFT_BASE:=.c))
O_FILES_LIBFT_BASE = \
	$(FILES_LIBFT_BASE:=.o)
 
# END LIBFT_BASE
# START GET_NEXT_LINE:

DIR_GET_NEXT_LINE = \
	$(DIR_SRC)

FILES_GET_NEXT_LINE = \
	ft_get_next_line

C_FILES_GET_NEXT_LINE = \
	$(addprefix $(DIR_GET_NEXT_LINE), $(FILES_GET_NEXT_LINE:=.c))
O_FILES_GET_NEXT_LINE = \
	$(FILES_GET_NEXT_LINE:=.o)

# END GET_NEXT_LINE
# START FT_PRINTF:

DIR_FT_PRINTF = \
	$(addprefix $(DIR_SRC), ft_printf/)
DIR_FT_PRINTF_UTIL = \
	$(addprefix $(DIR_FT_PRINTF), pf_util/)
DIR_FT_PRINTF_CONVERION = \
	$(addprefix $(DIR_FT_PRINTF), pf_conversions/)

FILES_FT_PRINTF = \
	ft_printf pf_append pf_padding pf_prepend pf_read_instruction
FILES_FT_PRINTF_CONVERSION = \
	pf_b pf_c pf_di pf_f pf_j pf_ouxx pf_p pf_percent pf_r pf_s
FILES_FT_PRINTF_UTIL = \
	pf_10_power_n pf_itoa_base pf_memcpy pf_memset pf_uitoa_base \
	pf_wchar_byte_count pf_intlen pf_ldtoa pf_memmove pf_uintlen \
	pf_wchar pf_wstr

C_FILES_FT_PRINTF = \
	$(addprefix $(DIR_FT_PRINTF), $(FILES_FT_PRINTF:=.c)) \
	$(addprefix $(DIR_FT_PRINTF_CONVERION), $(FILES_FT_PRINTF_CONVERSION:=.c)) \
	$(addprefix $(DIR_FT_PRINTF_UTIL), $(FILES_FT_PRINTF_UTIL:=.c))
O_FILES_FT_PRINTF = \
	$(FILES_FT_PRINTF:=.o) \
	$(FILES_FT_PRINTF_CONVERSION:=.o) \
	$(FILES_FT_PRINTF_UTIL:=.o)

#END FT_PRINTF

NAME = libft.a

ALL_C_FILES = \
	$(C_FILES_LIBFT_BASE) $(C_FILES_GET_NEXT_LINE) $(C_FILES_FT_PRINTF)
ALL_O_FILES = \
	$(O_FILES_LIBFT_BASE) $(O_FILES_GET_NEXT_LINE) $(O_FILES_FT_PRINTF)


$(NAME):
	gcc -c -Wall -Wextra -Werror $(ALL_C_FILES) -I $(DIR_INCLUDES) -I.
	ar rc $(NAME) $(ALL_O_FILES)
	ranlib $(NAME)

clean:
	rm -f $(ALL_O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

all: $(NAME)

so:
	gcc -shared -o libft.so -I. -Wall -Wextra -Werror -fPIC $(ALL_C_FILES)
