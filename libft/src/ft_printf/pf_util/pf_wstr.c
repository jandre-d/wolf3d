/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_wstr.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 13:56:47 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/29 19:48:31 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline int	wstr_n_size(int *wstr, int32_t wchar_count_max)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (wstr[i] && i < wchar_count_max)
	{
		size += wchar_byte_count(wstr[i]);
		i++;
	}
	return (size);
}

char				*pf_wstr_to_str(int *wstr, int *size, int precision)
{
	char	*str;
	int		i;
	int		add_size;
	char	*add;

	str = ft_strnew(wstr_n_size(wstr, precision));
	i = 0;
	while (wstr[i] && i < precision)
	{
		add = pf_wchar_to_str(wstr[i], &add_size);
		pf_memcpy(str + *size, add, add_size);
		ft_memdel((void **)&add);
		*size += add_size;
		i++;
	}
	return (str);
}
