/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 12:49:58 by jandre-d       #+#    #+#                */
/*   Updated: 2019/07/09 16:47:30 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	error(t_error error, char *msg)
{
	if (error == cant_open_file)
		ft_printf("Error opening file \"%s\"\n", msg);
	else if (error == file_is_corrupted)
		ft_printf("Error corrupted file \"%s\"\n", msg);
	else if (error == error_reading)
		ft_printf("Error reading file \"%s\"\n", msg);
	else if (error == malloc_error)
		write(2, "Error allocating memory\n", 24);
	exit(1);
}
