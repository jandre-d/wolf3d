/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_percent.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:47:24 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/30 12:39:49 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	pf_percent(t_conversion_in *c_in, t_conversion_out *c_out)
{
	c_out->len = 1;
	c_out->str = ft_strnew(1);
	if (c_out->str == NULL)
		return (false);
	c_out->str[0] = '%';
	return (pf_padding_general(c_in, c_out, false));
}
