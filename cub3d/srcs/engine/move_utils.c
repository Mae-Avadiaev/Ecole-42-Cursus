/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:01:06 by mclown            #+#    #+#             */
/*   Updated: 2021/03/09 21:15:29 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	key_w_or_key_s(t_data *data, double movespeed)
{
	if (data->key.w == 1)
	{
		if (data->map_data.map[(int)data->pl.pos.y]
				[(int)(data->pl.pos.x + data->pl.dir.x * movespeed)] == '0')
			data->pl.pos.x += data->pl.dir.x * movespeed;
		if (data->map_data.map[(int)(data->pl.pos.y + data->pl.dir.y
					* movespeed)][(int)data->pl.pos.x] == '0')
			data->pl.pos.y += data->pl.dir.y * movespeed;
	}
	if (data->key.s == 1)
	{
		if (data->map_data.map[(int)data->pl.pos.y]
				[(int)(data->pl.pos.x - data->pl.dir.x * movespeed)] == '0')
			data->pl.pos.x -= data->pl.dir.x * movespeed;
		if (data->map_data.map[(int)(data->pl.pos.y - data->pl.dir.y
					* movespeed)][(int)data->pl.pos.x] == '0')
			data->pl.pos.y -= data->pl.dir.y * movespeed;
	}
}

void	key_a_or_key_d(t_data *data, double movespeed)
{
	if (data->key.a == 1)
	{
		if (data->map_data.map[(int)(data->pl.pos.y)]
				[(int)(data->pl.pos.x + data->pl.plane.x * movespeed)] == '0')
			data->pl.pos.x += data->pl.plane.x * movespeed;
		if (data->map_data.map[(int)(data->pl.pos.y + data->pl.plane.y
					* movespeed)][(int)(data->pl.pos.x)] == '0')
			data->pl.pos.y += data->pl.plane.y * movespeed;
	}
	if (data->key.d == 1)
	{
		if (data->map_data.map[(int)(data->pl.pos.y)]
				[(int)(data->pl.pos.x - data->pl.plane.x * movespeed)] == '0')
			data->pl.pos.x -= data->pl.plane.x * movespeed;
		if (data->map_data.map[(int)(data->pl.pos.y - data->pl.plane.y
					* movespeed)][(int)(data->pl.pos.x)] == '0')
			data->pl.pos.y -= data->pl.plane.y * movespeed;
	}
}

void	key_left_or_key_right(
		t_key key, t_pl *pl, t_algo_data algo_data, double rotspeed)
{
	if (key.left == 1)
	{
		algo_data.old_dir_x = pl->dir.x;
		pl->dir.x = pl->dir.x * cos(-rotspeed)
			- pl->dir.y * sin(-rotspeed);
		pl->dir.y = algo_data.old_dir_x * sin(-rotspeed)
			+ pl->dir.y * cos(-rotspeed);
		algo_data.old_plane_x = pl->plane.x;
		pl->plane.x = pl->plane.x * cos(-rotspeed)
			- pl->plane.y * sin(-rotspeed);
		pl->plane.y = algo_data.old_plane_x
			* sin(-rotspeed) + pl->plane.y * cos(-rotspeed);
	}
	if (key.right == 1)
	{
		algo_data.old_dir_x = pl->dir.x;
		pl->dir.x = pl->dir.x * cos(rotspeed) - pl->dir.y * sin(rotspeed);
		pl->dir.y = algo_data.old_dir_x
			* sin(rotspeed) + pl->dir.y * cos(rotspeed);
		algo_data.old_plane_x = pl->plane.x;
		pl->plane.x = pl->plane.x * cos(rotspeed) - pl->plane.y * sin(rotspeed);
		pl->plane.y = algo_data.old_plane_x
			* sin(rotspeed) + pl->plane.y * cos(rotspeed);
	}
}

int		key_pressed(int key, t_data *data)
{
	key == KEY_W ? data->key.w = 1 : 0;
	key == KEY_A ? data->key.a = 1 : 0;
	key == KEY_S ? data->key.s = 1 : 0;
	key == KEY_D ? data->key.d = 1 : 0;
	key == KEY_LEFT ? data->key.left = 1 : 0;
	key == KEY_RIGHT ? data->key.right = 1 : 0;
	key == KEY_ESC ? exit(0) : 0;
	return (0);
}

int		key_released(int key, t_data *data)
{
	key == KEY_W ? data->key.w = 0 : 0;
	key == KEY_A ? data->key.a = 0 : 0;
	key == KEY_S ? data->key.s = 0 : 0;
	key == KEY_D ? data->key.d = 0 : 0;
	key == KEY_LEFT ? data->key.left = 0 : 0;
	key == KEY_RIGHT ? data->key.right = 0 : 0;
	return (0);
}
