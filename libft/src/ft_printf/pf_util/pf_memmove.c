/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 10:48:56 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/29 19:48:31 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_memmove(char *dst, char *src, size_t len)
{
	return ((char *)ft_memmove((void *)dst, (const void *)src, len));
}
