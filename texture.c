/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/05 15:29:47 by jandre-d       #+#    #+#                */
/*   Updated: 2019/07/09 16:52:25 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static inline void	texture_init(t_wolf *wolf)
{
	if (wolf->d_var.side == EAST || wolf->d_var.side == WEST)
		wolf->d_var.perp_wall_dist = (wolf->d_var.map.x - wolf->pos.x +
			(1 - wolf->d_var.step.x) / 2) / wolf->d_var.ray_dir.x;
	else
		wolf->d_var.perp_wall_dist = (wolf->d_var.map.y - wolf->pos.y +
			(1 - wolf->d_var.step.y) / 2) / wolf->d_var.ray_dir.y;
	wolf->d_var.line_height = (int)(HEIGHT / wolf->d_var.perp_wall_dist);
	wolf->d_var.draw_start = -wolf->d_var.line_height / 2 + HEIGHT / 2;
	if (wolf->d_var.draw_start < 0)
		wolf->d_var.draw_start = 0;
	wolf->d_var.draw_end = wolf->d_var.line_height / 2 + HEIGHT / 2;
	if (wolf->d_var.draw_end >= HEIGHT)
		wolf->d_var.draw_end = HEIGHT - 1;
	if (wolf->d_var.side == EAST || wolf->d_var.side == WEST)
		wolf->d_var.wall_x = wolf->pos.y + wolf->d_var.perp_wall_dist *
			wolf->d_var.ray_dir.y;
	else
		wolf->d_var.wall_x = wolf->pos.x + wolf->d_var.perp_wall_dist *
			wolf->d_var.ray_dir.x;
}

void				texture(t_wolf *wolf, int x)
{
	int			y;
	int			add;
	unsigned	color;

	texture_init(wolf);
	y = wolf->d_var.draw_start;
	wolf->d_var.wall_x -= floor((wolf->d_var.wall_x));
	wolf->d_var.tex_x = (int)(wolf->d_var.wall_x * (double)TEXTURE_SIZE);
	while (y < wolf->d_var.draw_end)
	{
		add = (y << 1) + wolf->d_var.line_height - HEIGHT;
		wolf->d_var.tex_y = ((add * TEXTURE_SIZE) /
			wolf->d_var.line_height) >> 1;
		color = wolf->textures[wolf->d_var.side][TEXTURE_SIZE *
			wolf->d_var.tex_y + wolf->d_var.tex_x];
		image_set_pixel(wolf->img_data_ptr, x, y, color);
		y++;
	}
}
