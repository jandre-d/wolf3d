/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/30 16:02:20 by jandre-d       #+#    #+#                */
/*   Updated: 2019/07/09 16:43:41 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	load_texture_to(char *filename, unsigned *to)
{
	int		fd;
	void	*to_data;

	to_data = (void *)to;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		error(cant_open_file, filename);
	}
	if (read(fd, to_data, TEXTURE_SIZE_BYTES) != TEXTURE_SIZE_BYTES)
	{
		close(fd);
		error(file_is_corrupted, filename);
	}
	close(fd);
}

static void	load_textures(t_wolf *wolf)
{
	load_texture_to("Resource/Texture/bluestone", wolf->textures[0]);
	load_texture_to("Resource/Texture/greystone", wolf->textures[1]);
	load_texture_to("Resource/Texture/redbrick", wolf->textures[2]);
	load_texture_to("Resource/Texture/wood", wolf->textures[3]);
}

static void	start(t_wolf *wolf)
{
	wolf->rot_speed = 12;
	wolf->move_speed = 0.24;
	wolf->pos.x = wolf->level.player_start.x + 0.5;
	wolf->pos.y = wolf->level.player_start.y + 0.5;
	wolf->dir.x = 1;
	wolf->dir.y = 0;
	wolf->plane.x = 0;
	wolf->plane.y = 0.66;
}

int			close_prog(void *param)
{
	(void)param;
	exit(0);
}

int			main(void)
{
	t_wolf wolf;

	wolf.mlx_ptr = mlx_init();
	wolf.win_ptr = mlx_new_window(wolf.mlx_ptr, WIDTH, HEIGHT, "Raycaster");
	wolf.img_ptr = mlx_new_image(wolf.mlx_ptr, WIDTH, HEIGHT);
	wolf.img_data_ptr = image_get_data_ptr(wolf.img_ptr);
	load_textures(&wolf);
	load_map(&wolf, "Resource/map");
	start(&wolf);
	draw(&wolf);
	mlx_hook(wolf.win_ptr, 2, 42, key_press, &wolf);
	mlx_hook(wolf.win_ptr, 17, 42, close_prog, &wolf);
	mlx_loop(wolf.mlx_ptr);
	return (1);
}
