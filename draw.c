/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/05 15:28:46 by jandre-d       #+#    #+#                */
/*   Updated: 2019/07/08 10:34:32 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static inline void	image_set_background(unsigned *img_data)
{
	int max;
	int	half;
	int i;

	max = WIDTH * HEIGHT;
	half = max / 2;
	i = 0;
	while (i < half)
	{
		img_data[i] = 0x93939;
		i++;
	}
	while (i < max)
	{
		img_data[i] = 0x6d6d6d;
		i++;
	}
}

void				draw(t_wolf *wolf)
{
	int x;

	x = 0;
	image_clear(wolf->img_data_ptr);
	image_set_background(wolf->img_data_ptr);
	while (x < WIDTH)
	{
		if (dda(wolf, x))
		{
			texture(wolf, x);
		}
		x++;
	}
	image_push(wolf);
}
