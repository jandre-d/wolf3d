/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_image.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/30 16:12:37 by jandre-d       #+#    #+#                */
/*   Updated: 2019/07/05 17:10:22 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

unsigned	*image_get_data_ptr(void *img_ptr)
{
	int trash;

	return ((unsigned *)mlx_get_data_addr(img_ptr,
		&trash, &trash, &trash));
}

void		image_push(t_wolf *wolf_ptr)
{
	mlx_put_image_to_window(
		wolf_ptr->mlx_ptr, wolf_ptr->win_ptr, wolf_ptr->img_ptr, 0, 0);
}

void		image_set_pixel(unsigned *img_data, int x, int y,
	unsigned color)
{
	if (y < HEIGHT && x < WIDTH && y >= 0 && x >= 0)
		img_data[(y * WIDTH) + x] = color;
}

void		image_clear(unsigned *img_data)
{
	ft_memset((void *)img_data, 0, BPP * WIDTH * HEIGHT);
}
