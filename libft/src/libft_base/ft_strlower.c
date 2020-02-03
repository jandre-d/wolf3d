/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlower.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/01 15:29:52 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/01 15:35:11 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strlower(char *str)
{
	while (*str)
	{
		*str = ft_tolower(*str);
		str++;
	}
}
