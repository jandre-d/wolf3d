/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/26 13:49:50 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/29 19:48:31 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_memset(char *str, char value, int32_t n)
{
	int32_t i;

	i = 0;
	while (i < n)
	{
		str[i] = value;
		i++;
	}
	return (str);
}
