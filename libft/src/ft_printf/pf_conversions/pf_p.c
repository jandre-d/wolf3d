/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_p.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:47:20 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/30 12:39:57 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	pf_p(t_conversion_in *c_in, t_conversion_out *c_out, va_list *argl)
{
	if (c_in->precision_default == false && c_in->precision == 0)
	{
		(void)va_arg(*argl, uint64_t);
		c_out->str = ft_strnew(0);
		c_out->len = 0;
	}
	else
		c_out->str = pf_uitoa_base(va_arg(*argl, uint64_t),
			16, c_out, true);
	if (c_out->str == NULL)
		return (false);
	pf_padding(c_out, '0', true, c_in->precision);
	if (c_in->flag_0)
		c_in->padding -= 2;
	else
		pf_prepend_to_c_out(c_out, "0x", 2);
	if (pf_padding_general(c_in, c_out, false) == false)
		return (false);
	if (c_in->flag_0)
		pf_prepend_to_c_out(c_out, "0x", 2);
	return (true);
}
