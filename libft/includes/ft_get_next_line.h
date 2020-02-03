/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_get_next_line.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 10:48:53 by jandre-d       #+#    #+#                */
/*   Updated: 2019/07/09 16:49:43 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H
# define BUFF_SIZE 42
# include <unistd.h>
# include <stdlib.h>
# include "../libft.h"

typedef struct			s_fd_list
{
	ssize_t				fd;
	ssize_t				buffer_usage;
	char				*buffer;
	struct s_fd_list	*next;
}						t_fd_list;

int						ft_get_next_line(const int fd, char **line);

#endif
