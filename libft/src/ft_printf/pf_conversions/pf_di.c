/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_di.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 15:07:22 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/30 12:40:09 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline bool	flags_and_mods(t_conversion_in *c_in,
	t_conversion_out *c_out)
{
	if (c_in->precision_default == false)
		c_in->flag_0 = false;
	if (((c_in->flag_plus || c_in->flag_space || c_out->is_negative) &&
		c_in->flag_0))
		c_in->padding -= 1;
	if (c_in->flag_0)
		if (pf_padding_general(c_in, c_out, false) == false)
			return (false);
	if (c_in->flag_plus && c_out->is_negative == false)
	{
		if (pf_prepend_to_c_out(c_out, "+", 1) == false)
			return (false);
	}
	else if (c_in->flag_space && c_out->is_negative == false)
	{
		if (pf_prepend_to_c_out(c_out, " ", 1) == false)
			return (false);
	}
	if (c_out->is_negative)
		if (pf_prepend_to_c_out(c_out, "-", 1) == false)
			return (false);
	if (pf_padding_general(c_in, c_out, false) == false)
		return (false);
	return (true);
}

bool				pf_di(t_conversion_in *c_in, t_conversion_out *c_out,
	va_list *argl)
{
	int64_t value;

	if (
		(c_in->mod_hh && ((value = (char)va_arg(*argl, int)) || 1)) ||
		(c_in->mod_h && ((value = (short)va_arg(*argl, int)) || 1)) ||
		(c_in->mod_l && ((value = va_arg(*argl, long)) || 1)) ||
		(c_in->mod_ll && ((value = va_arg(*argl, long long)) || 1)) ||
		((value = va_arg(*argl, int)) || 1))
		;
	if (value == 0 && c_in->precision_default == false && c_in->precision == 0)
	{
		c_out->str = ft_strnew(0);
		c_out->len = 0;
	}
	else
	{
		c_out->str = pf_itoa_base(value, 10, c_out, true);
		pf_padding(c_out, '0', true, c_in->precision);
		if (c_out->str == NULL)
			return (false);
	}
	return (flags_and_mods(c_in, c_out));
}
