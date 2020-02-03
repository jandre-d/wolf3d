/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_input.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/05 17:01:25 by jandre-d       #+#    #+#                */
/*   Updated: 2019/07/09 16:37:38 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static inline void	forwards(t_wolf *wolf)
{
	double move_x;
	double move_y;

	move_x = wolf->dir.x * wolf->move_speed;
	move_y = wolf->dir.y * wolf->move_speed;
	if (wolf->level.map[(int)(wolf->pos.x + move_x)][(int)wolf->pos.y] !=
		WALL_CHAR)
		wolf->pos.x += move_x;
	if (wolf->level.map[(int)wolf->pos.x][(int)(wolf->pos.y + move_y)] !=
		WALL_CHAR)
		wolf->pos.y += move_y;
}

static inline void	backwards(t_wolf *wolf)
{
	double move_x;
	double move_y;

	move_x = wolf->dir.x * wolf->move_speed;
	move_y = wolf->dir.y * wolf->move_speed;
	if (wolf->level.map[(int)(wolf->pos.x - move_x)][(int)wolf->pos.y] !=
		WALL_CHAR)
		wolf->pos.x -= move_x;
	if (wolf->level.map[(int)wolf->pos.x][(int)(wolf->pos.y - move_y)] !=
		WALL_CHAR)
		wolf->pos.y -= move_y;
}

static inline void	player_rotate(t_wolf *wolf, double deg)
{
	double x;
	double rad;

	rad = deg * PI_OVER_180;
	x = wolf->dir.x;
	wolf->dir.x = x * cos(rad) - wolf->dir.y * sin(rad);
	wolf->dir.y = x * sin(rad) + wolf->dir.y * cos(rad);
	x = wolf->plane.x;
	wolf->plane.x = x * cos(rad) - wolf->plane.y * sin(rad);
	wolf->plane.y = x * sin(rad) + wolf->plane.y * cos(rad);
}

int					key_press(int key, void *wolf_in)
{
	t_wolf *wolf;

	wolf = (t_wolf *)wolf_in;
	if (key == 126)
		forwards(wolf);
	else if (key == 125)
		backwards(wolf);
	else if (key == 123)
		player_rotate(wolf, -wolf->rot_speed);
	else if (key == 124)
		player_rotate(wolf, wolf->rot_speed);
	else if (key == 53)
		exit(1);
	draw(wolf);
	return (1);
}
