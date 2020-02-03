/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_b.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/27 20:02:30 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/30 17:32:08 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	pf_b(t_conversion_in *c_in, t_conversion_out *c_out, va_list *argl)
{
	uint64_t value;

	if ((c_in->mod_hh &&
		((value = (unsigned char)va_arg(*argl, unsigned int))
			|| 1)) ||
		(c_in->mod_h && ((value = (unsigned short)va_arg(*argl, unsigned int))
			|| 1))
		|| (c_in->mod_l && ((value = va_arg(*argl, unsigned long)) || 1))
		|| (c_in->mod_ll && ((value = va_arg(*argl, unsigned long long)) || 1))
		|| ((value = va_arg(*argl, unsigned int)) || 1))
		;
	c_out->str = pf_uitoa_base(value, 2, c_out, true);
	return (c_out->str != NULL);
}
