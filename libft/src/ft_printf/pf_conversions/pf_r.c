/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_r.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/27 20:02:52 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/30 12:39:45 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	pf_r(t_conversion_in *c_in, t_conversion_out *c_out, va_list *argl)
{
	return (pf_s(c_in, c_out, argl));
}
