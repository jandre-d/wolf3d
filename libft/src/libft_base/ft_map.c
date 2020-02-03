/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_map.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/01 15:10:02 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/30 12:32:05 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

double	ft_map(double x, double in_max, double out_min, double out_max)
{
	return (x * (out_max - out_min) / in_max + out_min);
}
