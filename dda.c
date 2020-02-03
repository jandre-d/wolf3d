/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dda.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/05 15:30:15 by jandre-d       #+#    #+#                */
/*   Updated: 2019/07/09 16:34:53 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static inline void	init_dda(t_wolf *wolf, int x)
{
	wolf->d_var.camera_x = 2 * x / (double)WIDTH - 1;
	wolf->d_var.ray_dir.x = wolf->dir.x + wolf->plane.x * wolf->d_var.camera_x;
	wolf->d_var.ray_dir.y = wolf->dir.y + wolf->plane.y * wolf->d_var.camera_x;
	wolf->d_var.map.x = (int)wolf->pos.x;
	wolf->d_var.map.y = (int)wolf->pos.y;
	wolf->d_var.delta.x = fabs(1 / wolf->d_var.ray_dir.x);
	wolf->d_var.delta.y = fabs(1 / wolf->d_var.ray_dir.y);
	wolf->d_var.step.x = wolf->d_var.ray_dir.x < 0 ? -1 : 1;
	wolf->d_var.step.y = wolf->d_var.ray_dir.y < 0 ? -1 : 1;
	if (wolf->d_var.ray_dir.x < 0)
		wolf->d_var.side_dist.x = (wolf->pos.x - wolf->d_var.map.x) *
			wolf->d_var.delta.x;
	else
		wolf->d_var.side_dist.x = (wolf->d_var.map.x + 1.0 - wolf->pos.x) *
			wolf->d_var.delta.x;
	if (wolf->d_var.ray_dir.y < 0)
		wolf->d_var.side_dist.y = (wolf->pos.y - wolf->d_var.map.y) *
			wolf->d_var.delta.y;
	else
		wolf->d_var.side_dist.y = (wolf->d_var.map.y + 1.0 - wolf->pos.y) *
			wolf->d_var.delta.y;
}

bool				dda(t_wolf *wolf, int x)
{
	int i;

	i = 0;
	init_dda(wolf, x);
	while (i < 420)
	{
		if (wolf->d_var.side_dist.x < wolf->d_var.side_dist.y)
		{
			wolf->d_var.side_dist.x += wolf->d_var.delta.x;
			wolf->d_var.map.x += wolf->d_var.step.x;
			wolf->d_var.side = wolf->d_var.ray_dir.x < 0 ? WEST : EAST;
		}
		else
		{
			wolf->d_var.side_dist.y += wolf->d_var.delta.y;
			wolf->d_var.map.y += wolf->d_var.step.y;
			wolf->d_var.side = wolf->d_var.ray_dir.y < 0 ? SOUTH : NORTH;
		}
		if (wolf->level.map[wolf->d_var.map.x][wolf->d_var.map.y] == WALL_CHAR)
			return (true);
		i++;
	}
	return (false);
}
