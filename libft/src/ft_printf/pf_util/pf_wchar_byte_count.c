/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_wchar_byte_count.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 13:59:23 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/29 19:48:31 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	wchar_byte_count(int wchar)
{
	if (wchar <= 0x7F)
		return (1);
	if (wchar <= 0x7FF)
		return (2);
	if (wchar <= 0xFFFF)
		return (3);
	return (4);
}
