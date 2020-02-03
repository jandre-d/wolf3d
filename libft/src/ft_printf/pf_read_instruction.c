/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_read_instruction.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 11:38:33 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/29 19:50:44 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline bool		set_conversion(char **str, t_conversion_in *c_in)
{
	if (**str == 'c' ||
		**str == 's' ||
		**str == 'p' ||
		**str == 'd' ||
		**str == 'i' ||
		**str == 'o' ||
		**str == 'u' ||
		**str == 'X' ||
		**str == 'x' ||
		**str == 'f' ||
		**str == 'r' ||
		**str == 'b' ||
		**str == 'j' ||
		**str == '%')
	{
		c_in->conversion_type = **str;
		return (true);
	}
	return (false);
}

/*
** ll hh
*/

static inline uint8_t	set_flag_double_char(char **str, t_conversion_in *c_in)
{
	if (**str == 'l' && c_in->mod_l)
	{
		if (*(*str - 1) == 'l')
		{
			c_in->mod_ll = true;
			c_in->mod_l = false;
			return (true);
		}
		return (false);
	}
	if (**str == 'h' && c_in->mod_h)
	{
		if (*(*str - 1) == 'h')
		{
			c_in->mod_hh = true;
			c_in->mod_h = false;
			return (true);
		}
		return (false);
	}
	return (42);
}

static inline bool		set_nbr_param(char **str, t_conversion_in *c_in)
{
	bool	is_precision;
	int32_t i;

	i = 0;
	is_precision = **str == '.';
	if (is_precision)
		*str += 1;
	while (**str && **str >= '0' && **str <= '9')
	{
		i *= 10;
		i += **str - '0';
		*str += 1;
	}
	if (is_precision)
	{
		c_in->precision = i;
		c_in->precision_default = false;
	}
	else
		c_in->padding = i;
	*str -= 1;
	return (true);
}

/*
** # 0 - + space h l L
*/

static inline bool		set_flag_and_mod(char **str, t_conversion_in *c_in)
{
	uint8_t double_char_flag_result;

	double_char_flag_result = set_flag_double_char(str, c_in);
	if (double_char_flag_result == 42)
		return (
			(**str == '0' && (c_in->flag_0 = true)) ||
			(**str == '-' && (c_in->flag_min = true)) ||
			(**str == '+' && (c_in->flag_plus = true)) ||
			(**str == ' ' && (c_in->flag_space = true)) ||
			(**str == '#' && (c_in->flag_hash = true)) ||
			(**str == 'h' && (c_in->mod_h = true)) ||
			(**str == 'l' && (c_in->mod_l = true)) ||
			(**str == 'L' && (c_in->mod_l_upper = true)) ||
			(**str == '.' && set_nbr_param(str, c_in)) ||
			((**str >= '0' && **str <= '9') && set_nbr_param(str, c_in)));
	else
		return (double_char_flag_result != false);
}

/*
** the first character in str should be a '%'
*/

bool					pf_read_instruction(char **str, t_conversion_in *c_in)
{
	c_in->precision_default = true;
	if (**str != '\0')
	{
		while (true)
		{
			*str += 1;
			if (**str == '\0')
				return (false);
			if (set_flag_and_mod(str, c_in))
				continue;
			else if (set_conversion(str, c_in))
				return (true);
			else
				return (false);
		}
	}
	return (false);
}
