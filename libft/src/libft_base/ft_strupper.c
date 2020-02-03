/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strupper.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/01 15:28:05 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/01 15:35:03 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strupper(char *str)
{
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
}
