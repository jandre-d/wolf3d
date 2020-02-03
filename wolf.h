/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wolf.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/30 16:13:06 by jandre-d       #+#    #+#                */
/*   Updated: 2019/07/09 16:48:36 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <stdbool.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>

# define WIDTH 1366
# define HEIGHT 768
# define BPP 4
# define TEXTURE_SIZE 64
# define TEXTURE_SIZE_BYTES TEXTURE_SIZE * TEXTURE_SIZE * BPP
# define PI_OVER_180 0.0174532925199432957692
# define NORTH 0
# define EAST 1
# define SOUTH 2
# define WEST 3

# define WALL_CHAR '@'
# define PLAYER_START_CHAR 'P'
# define EMPTY_CHAR '='

typedef enum	e_error
{
	cant_open_file,
	file_is_corrupted,
	error_reading,
	malloc_error
}				t_error;

typedef struct	s_vector2
{
	double x;
	double y;
}				t_vector2;

typedef struct	s_vector2_int
{
	int x;
	int y;
}				t_vector2_int;

typedef struct	s_draw_vars
{
	double			camera_x;
	t_vector2		ray_dir;
	t_vector2_int	map;
	t_vector2		delta;
	t_vector2		side_dist;
	t_vector2_int	step;
	double			perp_wall_dist;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	unsigned		color;
	double			wall_x;
	int				tex_x;
	int				tex_y;
}				t_draw_vars;

typedef struct	s_load_map
{
	int				fd;
	char			*filename;
	char			*line;
	char			*previous_line;
	int				line_len;
	int				line_count;
	int				target_line_len;
	bool			player_start_found;
	t_vector2_int	player_start_index;
	int				gnl_ret;
}				t_load_map;

typedef struct	s_map
{
	char			**map;
	t_vector2_int	player_start;
	t_vector2_int	map_size;
}				t_map;

typedef struct	s_wolf
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	unsigned	*img_data_ptr;
	unsigned	textures[4][TEXTURE_SIZE * TEXTURE_SIZE];
	t_draw_vars	d_var;
	double		move_speed;
	double		rot_speed;
	t_vector2	pos;
	t_vector2	dir;
	t_vector2	plane;
	t_map		level;
	t_load_map	l_var;
}				t_wolf;

void			load_map(t_wolf *wolf, char *filename);
void			error(t_error error, char *msg);
void			texture(t_wolf *wolf, int x);
bool			dda(t_wolf *wolf, int x);
void			draw(t_wolf *wolf);
int				key_press(int key, void *wolf_in);
unsigned		*image_get_data_ptr(void *img_ptr);
void			image_push(t_wolf *wolf_ptr);
void			image_set_pixel(unsigned *img_data, int x, int y,
	unsigned color);
void			image_clear(unsigned *img_data);

#endif
