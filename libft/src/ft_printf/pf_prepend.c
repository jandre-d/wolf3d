/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_prepend.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 17:20:30 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/29 19:50:41 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	pf_prepend_to_c_out(t_conversion_out *c_out, char *str, int32_t len)
{
	char *new_str;

	new_str = ft_strnew(c_out->len);
	if (new_str == NULL)
		return (false);
	pf_memcpy(new_str, str, len);
	pf_memcpy(new_str + len, c_out->str, c_out->len);
	c_out->len += len;
	ft_memdel((void **)&c_out->str);
	c_out->str = new_str;
	return (true);
}

bool	pf_prepend(t_pf_output *output, char *str, size_t str_len,
	bool free_str)
{
	char	*new_output_str;
	size_t	new_size;

	if (output->str_useage + str_len > output->str_size - 1)
	{
		new_size = output->str_useage + str_len + 50;
		new_output_str = ft_strnew(new_size);
		if (new_output_str == NULL)
			return (false);
		pf_memcpy(new_output_str, str, str_len);
		pf_memcpy(new_output_str + str_len, output->str, output->str_useage);
		ft_memdel((void **)&output->str);
		output->str_size = new_size;
		output->str_useage = new_size - 50;
		output->str = new_output_str;
	}
	else
	{
		pf_memmove(output->str + str_len, output->str, output->str_useage);
		pf_memcpy(output->str, str, str_len);
		output->str_useage += str_len;
	}
	if (free_str)
		ft_memdel((void **)&str);
	return (true);
}
