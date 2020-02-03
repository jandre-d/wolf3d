/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strislower.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/01 15:33:28 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/01 15:35:22 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strislower(char *str)
{
	while (*str)
	{
		if (ft_islower(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}
