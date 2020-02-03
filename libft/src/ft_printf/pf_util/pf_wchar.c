/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_wchar.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 21:26:20 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/29 19:48:31 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline void	pf_wchar_to_str_size_4(int wchar, char *to_return)
{
	to_return[3] = (char)(0x80 | (wchar & 0x3F));
	to_return[2] = (char)(0x80 | ((wchar >> 6) & 0x3F));
	to_return[1] = (char)(0x80 | ((wchar >> 12) & 0x3F));
	to_return[0] = (char)(0xF0 | ((wchar >> 12) & 0x7));
}

char				*pf_wchar_to_str(int wchar, int *size)
{
	char *to_return;

	*size = wchar_byte_count(wchar);
	to_return = ft_strnew(*size);
	if (to_return == NULL)
		return (NULL);
	if (*size == 1)
		to_return[0] = wchar;
	if (*size == 2)
	{
		to_return[1] = (char)(0x80 | (wchar & 0x3F));
		to_return[0] = (char)(0xC0 | ((wchar >> 6) & 0x1F));
	}
	if (*size == 3)
	{
		to_return[2] = (char)(0x80 | (wchar & 0x3F));
		to_return[1] = (char)(0x80 | ((wchar >> 6) & 0x3F));
		to_return[0] = (char)(0xE0 | ((wchar >> 12) & 0xF));
	}
	if (*size == 4)
		pf_wchar_to_str_size_4(wchar, to_return);
	return (to_return);
}
