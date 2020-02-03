/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_s.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:35:06 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/30 12:39:41 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	set_null_text(t_conversion_out *c_out)
{
	char *nul;

	nul = "(null)";
	c_out->len = 6;
	c_out->str = ft_strnew(6);
	if (c_out->str == NULL)
		return (false);
	pf_memcpy(c_out->str, nul, c_out->len);
	return (true);
}

static bool	for_str(t_conversion_out *c_out, va_list *argl, int precision)
{
	char *str;

	str = va_arg(*argl, char *);
	if (str == NULL)
		return (set_null_text(c_out));
	c_out->len = ft_strlen(str);
	if (precision > 0)
		if (c_out->len > precision)
			c_out->len = precision;
	c_out->str = ft_strnew(c_out->len);
	if (c_out->str == NULL)
		return (false);
	pf_memcpy(c_out->str, str, c_out->len);
	return (true);
}

static bool	for_wstr(t_conversion_out *c_out, va_list *argl, int precision)
{
	int *wstr;

	wstr = va_arg(*argl, int *);
	if (wstr == NULL)
		return (set_null_text(c_out));
	c_out->str = pf_wstr_to_str(wstr, &c_out->len, precision);
	if (c_out->str == NULL)
		return (false);
	return (true);
}

bool		pf_s(t_conversion_in *c_in, t_conversion_out *c_out, va_list *argl)
{
	if (c_in->precision_default == false && c_in->precision == 0)
	{
		c_out->str = ft_strnew(0);
		c_out->len = 0;
	}
	else if (c_in->mod_l)
	{
		if (c_in->precision_default)
		{
			if (for_wstr(c_out, argl, __INT32_MAX__) == false)
				return (false);
		}
		else if (for_wstr(c_out, argl, c_in->precision) == false)
			return (false);
	}
	else
	{
		for_str(c_out, argl, c_in->precision);
	}
	return (pf_padding_general(c_in, c_out, false));
}
