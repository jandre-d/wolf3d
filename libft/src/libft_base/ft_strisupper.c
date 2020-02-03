/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strisupper.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/01 15:31:18 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/01 15:33:58 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strisupper(char *str)
{
	while (*str)
	{
		if (ft_isupper(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}
