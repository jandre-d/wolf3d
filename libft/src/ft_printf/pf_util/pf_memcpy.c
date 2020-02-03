/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 11:05:25 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/29 19:48:31 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_memcpy(char *dst, char *src, size_t n)
{
	return ((char *)ft_memcpy((void *)dst, (const void *)src, n));
}
