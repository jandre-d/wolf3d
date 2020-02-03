/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 11:58:01 by jandre-d       #+#    #+#                */
/*   Updated: 2019/07/09 16:43:51 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static	inline void	first_or_last_line(t_load_map *l_var)
{
	int i;

	i = 0;
	while (l_var->line[i])
	{
		if (l_var->line[i] != WALL_CHAR)
			error(file_is_corrupted, l_var->filename);
		i++;
	}
	if (i == 0)
		error(file_is_corrupted, l_var->filename);
	if (l_var->target_line_len == 0)
	{
		l_var->target_line_len = i;
		l_var->line_count++;
	}
	else
	{
		if (l_var->target_line_len != i)
			error(file_is_corrupted, l_var->filename);
		close(l_var->fd);
	}
	l_var->line_len = i;
}

static inline void	middle_line(t_load_map *l_var)
{
	int i;

	i = 0;
	while (l_var->line[i])
	{
		if (l_var->line[i] == WALL_CHAR ||
		(l_var->line[i] == PLAYER_START_CHAR &&
		l_var->player_start_found == false) ||
		l_var->line[i] == EMPTY_CHAR)
		{
			if (l_var->line[i] == PLAYER_START_CHAR)
			{
				l_var->player_start_found = true;
				l_var->player_start_index.x = i;
				l_var->player_start_index.y = l_var->line_count;
			}
		}
		else
			error(file_is_corrupted, l_var->filename);
		i++;
	}
	if (i == 0 || l_var->target_line_len != i)
		error(file_is_corrupted, l_var->filename);
	l_var->line_len = i;
	l_var->line_count++;
}

static inline void	get_map_size_and_check_valid(t_wolf *wolf, char *filename)
{
	ft_bzero(&wolf->l_var, sizeof(t_load_map));
	wolf->l_var.filename = filename;
	wolf->l_var.fd = open(filename, O_RDONLY);
	if (wolf->l_var.fd == -1)
		error(cant_open_file, filename);
	wolf->l_var.gnl_ret = ft_get_next_line(wolf->l_var.fd, &wolf->l_var.line);
	while (wolf->l_var.gnl_ret == 1)
	{
		if (wolf->l_var.target_line_len == 0)
			first_or_last_line(&wolf->l_var);
		else
		{
			ft_memdel((void *)&wolf->l_var.previous_line);
			middle_line(&wolf->l_var);
		}
		wolf->l_var.previous_line = wolf->l_var.line;
		wolf->l_var.gnl_ret =
			ft_get_next_line(wolf->l_var.fd, &wolf->l_var.line);
	}
	if (wolf->l_var.gnl_ret == -1 || wolf->l_var.line_count < 3)
		error(error_reading, filename);
	ft_memdel((void *)&wolf->l_var.line);
	wolf->l_var.line = wolf->l_var.previous_line;
	first_or_last_line(&wolf->l_var);
	ft_memdel((void *)&wolf->l_var.line);
}

void				load_map(t_wolf *wolf, char *filename)
{
	int i;

	i = 0;
	get_map_size_and_check_valid(wolf, filename);
	wolf->l_var.fd = open(wolf->l_var.filename, O_RDONLY);
	if (wolf->l_var.fd == -1)
		error(cant_open_file, wolf->l_var.filename);
	wolf->level.map = ft_memalloc(sizeof(char *) * wolf->l_var.line_count);
	if (wolf->level.map == NULL)
		error(malloc_error, NULL);
	while (i < wolf->l_var.line_count)
	{
		wolf->l_var.gnl_ret = ft_get_next_line(wolf->l_var.fd,
			&wolf->l_var.line);
		if (wolf->l_var.gnl_ret == -1)
			error(error_reading, wolf->l_var.filename);
		wolf->level.map[i] = wolf->l_var.line;
		i++;
	}
	wolf->level.map_size.x = wolf->l_var.target_line_len;
	wolf->level.map_size.y = wolf->l_var.line_count;
	wolf->level.player_start.x = wolf->l_var.player_start_index.x;
	wolf->level.player_start.y = wolf->l_var.player_start_index.y;
}
