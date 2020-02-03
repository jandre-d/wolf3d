/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_j.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/27 20:16:39 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/30 12:40:03 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline bool	set_null_text(t_conversion_out *c_out)
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

static inline void	rot_str(char *rot_str, int32_t offset)
{
	int32_t i;

	i = 0;
	while (rot_str[i])
	{
		rot_str[i] -= 32;
		rot_str[i] = (rot_str[i] + offset) % (127 - 32);
		rot_str[i] += 32;
		i++;
	}
}

bool				pf_j(t_conversion_in *c_in, t_conversion_out *c_out,
	va_list *argl)
{
	int32_t	len;
	char	*str_in;

	str_in = va_arg(*argl, char *);
	if (str_in == NULL)
		return (set_null_text(c_out));
	len = ft_strlen(str_in);
	c_out->str = ft_strnew(len);
	if (c_out->str == NULL)
		return (false);
	c_out->len = len;
	pf_memcpy(c_out->str, str_in, len);
	rot_str(c_out->str, c_in->precision);
	return (true);
}
