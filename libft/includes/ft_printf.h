/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/06 12:29:23 by jandre-d       #+#    #+#                */
/*   Updated: 2019/07/09 14:04:44 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdint.h>
# include <stdbool.h>
# include <stdarg.h>
# include <unistd.h>
# include "../libft.h"

typedef struct	s_pf_output
{
	char	*str;
	size_t	str_size;
	size_t	str_useage;
}				t_pf_output;

typedef struct	s_conversion_output
{
	char	*str;
	int32_t	len;
	bool	is_negative;
	bool	has_decimal;
}				t_conversion_out;

typedef struct	s_conversion_input
{
	char		conversion_type;
	bool		mod_h;
	bool		mod_hh;
	bool		mod_l;
	bool		mod_ll;
	bool		mod_l_upper;
	bool		flag_hash;
	bool		flag_0;
	bool		flag_min;
	bool		flag_plus;
	bool		flag_space;
	int32_t		padding;
	int32_t		precision;
	bool		precision_default;
}				t_conversion_in;

typedef struct	s_ldbltoa_vars
{
	int64_t	integer_part;
	int64_t	decimal_part;
	int32_t	decimal_part_leading_zeros;
	int32_t len;
	char	*to_return;
}				t_ldbltoa_vars;

/*
** conversions
*/
bool			pf_c(t_conversion_in *c_in, t_conversion_out *c_out,
	va_list *argl);
bool			pf_di(t_conversion_in *c_in, t_conversion_out *c_out,
	va_list *argl);
bool			pf_f(t_conversion_in *c_in, t_conversion_out *c_out,
	va_list *argl);
bool			pf_ouxx(t_conversion_in *c_in, t_conversion_out *c_out,
	va_list *argl);
bool			pf_p(t_conversion_in *c_in, t_conversion_out *c_out,
	va_list *argl);
bool			pf_percent(t_conversion_in *c_in, t_conversion_out *c_out);
bool			pf_s(t_conversion_in *c_in, t_conversion_out *c_out,
	va_list *argl);
bool			pf_r(t_conversion_in *c_in, t_conversion_out *c_out,
	va_list *argl);
bool			pf_b(t_conversion_in *c_in, t_conversion_out *c_out,
	va_list *argl);
bool			pf_j(t_conversion_in *c_in, t_conversion_out *c_out,
	va_list *argl);

/*
** util
*/
int64_t			pf_10_power_n(int32_t n);
int8_t			pf_intlen(int64_t value, uint8_t base);
char			*pf_itoa_base(int64_t value, int8_t base,
	t_conversion_out *c_out, bool lowercase);
char			*pf_ldtoa(long double nbr, int32_t precision,
	t_conversion_out *c_out);
char			*pf_memcpy(char *dst, char *src, size_t n);
char			*pf_memmove(char *dst, char *src, size_t len);
char			*pf_memset(char *str, char value, int32_t n);
int8_t			pf_uintlen(uint64_t value, uint8_t base);
char			*pf_uitoa_base(uint64_t value, int8_t base,
	t_conversion_out *c_out, bool lowercase);
int				wchar_byte_count(int wchar);
char			*pf_wchar_to_str(int wchar, int *size);
char			*pf_wstr_to_str(int *wstr, int *size, int precision);

/*
** src other
*/
bool			pf_read_instruction(char **str, t_conversion_in *c_in);
bool			pf_append(t_pf_output *output, char *str, size_t str_len,
	bool free_str);
bool			pf_prepend(t_pf_output *output, char *str, size_t str_len,
	bool free_str);
bool			pf_padding(t_conversion_out *c_out, char padd_char,
	bool padd_left, int32_t min_width);
bool			pf_padding_general(t_conversion_in *c_in,
	t_conversion_out *c_out, bool ignore_zero_flag);
bool			pf_prepend_to_c_out(t_conversion_out *c_out, char *str,
	int32_t len);
bool			pf_append_to_c_out(t_conversion_out *c_out, char *str,
	int32_t len);

int				ft_printf(const char *format, ...);

#endif
