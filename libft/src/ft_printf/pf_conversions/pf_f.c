/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_f.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:47:14 by jandre-d       #+#    #+#                */
/*   Updated: 2019/05/08 16:44:38 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** does not work with high precision values becase i cast the decimal part \
** to a int64 (it will overflow)
*/

static inline bool	flags_and_mods(t_conversion_in *c_in,
	t_conversion_out *c_out)
{
	if (c_in->flag_hash && c_out->has_decimal == false)
		if (pf_append_to_c_out(c_out, ".", 1) == false)
			return (false);
	if ((c_in->flag_plus || c_in->flag_space) && c_in->flag_0)
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

bool				pf_f(t_conversion_in *c_in, t_conversion_out *c_out,
	va_list *argl)
{
	if (c_in->precision_default)
		c_in->precision = 6;
	if (c_in->mod_l_upper)
		c_out->str = pf_ldtoa(va_arg(*argl, long double), c_in->precision,
			c_out);
	else
		c_out->str = pf_ldtoa(va_arg(*argl, double), c_in->precision, c_out);
	if (c_out->str == NULL)
		return (false);
	return (flags_and_mods(c_in, c_out));
}
