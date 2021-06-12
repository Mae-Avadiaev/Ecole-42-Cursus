/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 21:31:26 by mclown            #+#    #+#             */
/*   Updated: 2021/03/10 17:45:34 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	def_texture_extra(t_data *data)
{
	if (data->algo_data.side == 1)
		data->txtr_data.text_num = SOUTH;
	else if (data->algo_data.side == 0)
		data->txtr_data.text_num = WEST;
}

void	def_texture(t_data *data)
{
	if (data->algo_data.ray_dir.x > 0 && data->algo_data.ray_dir.y > 0)
	{
		if (data->algo_data.side == 1)
			data->txtr_data.text_num = SOUTH;
		else if (data->algo_data.side == 0)
			data->txtr_data.text_num = EAST;
	}
	else if (data->algo_data.ray_dir.x >= 0 && data->algo_data.ray_dir.y < 0)
	{
		if (data->algo_data.side == 1)
			data->txtr_data.text_num = NORTH;
		else if (data->algo_data.side == 0)
			data->txtr_data.text_num = EAST;
	}
	else if (data->algo_data.ray_dir.x < 0 && data->algo_data.ray_dir.y < 0)
	{
		if (data->algo_data.side == 1)
			data->txtr_data.text_num = NORTH;
		else if (data->algo_data.side == 0)
			data->txtr_data.text_num = WEST;
	}
	else if (data->algo_data.ray_dir.x < 0 && data->algo_data.ray_dir.y > 0)
		def_texture_extra(data);
}

void	cr_part1(t_data *data, int x)
{
	data->algo_data.camera_x = 2.0 * x / (float)data->map_data.scr_w - 1;
	data->algo_data.ray_dir.x = data->pl.dir.x
		+ data->pl.plane.x * data->algo_data.camera_x;
	data->algo_data.ray_dir.y = data->pl.dir.y
		+ data->pl.plane.y * data->algo_data.camera_x;
	data->algo_data.map.x = (int)data->pl.pos.x;
	data->algo_data.map.y = (int)data->pl.pos.y;
	if (data->algo_data.ray_dir.y == 0)
		data->algo_data.delta_dist.x = 0;
	else
	{
		if (data->algo_data.ray_dir.x == 0)
			data->algo_data.delta_dist.x = 1;
		else
			data->algo_data.delta_dist.x = fabs(1 / data->algo_data.ray_dir.x);
	}
	if (data->algo_data.ray_dir.x == 0)
		data->algo_data.delta_dist.y = 0;
	else
	{
		if (data->algo_data.ray_dir.y == 0)
			data->algo_data.delta_dist.y = 1;
		else
			data->algo_data.delta_dist.y = fabs(1 / data->algo_data.ray_dir.y);
	}
}

void	cr_part2(t_data *data)
{
	if (data->algo_data.ray_dir.x < 0)
	{
		data->algo_data.step.x = -1;
		data->algo_data.side_dist.x = (data->pl.pos.x - data->algo_data.map.x)
			* data->algo_data.delta_dist.x;
	}
	else
	{
		data->algo_data.step.x = 1;
		data->algo_data.side_dist.x = (data->algo_data.map.x
				+ 1.0 - data->pl.pos.x) * data->algo_data.delta_dist.x;
	}
	if (data->algo_data.ray_dir.y < 0)
	{
		data->algo_data.step.y = -1;
		data->algo_data.side_dist.y = (data->pl.pos.y - data->algo_data.map.y)
			* data->algo_data.delta_dist.y;
	}
	else
	{
		data->algo_data.step.y = 1;
		data->algo_data.side_dist.y = (data->algo_data.map.y
				+ 1.0 - data->pl.pos.y) * data->algo_data.delta_dist.y;
	}
	data->algo_data.hit = 0;
}

void	cr_part3(t_data *data)
{
	if (data->algo_data.side_dist.x < data->algo_data.side_dist.y)
	{
		data->algo_data.side_dist.x += data->algo_data.delta_dist.x;
		data->algo_data.map.x += data->algo_data.step.x;
		data->algo_data.side = 0;
	}
	else
	{
		data->algo_data.side_dist.y += data->algo_data.delta_dist.y;
		data->algo_data.map.y += data->algo_data.step.y;
		data->algo_data.side = 1;
	}
	if (data->map_data.map[data->algo_data.map.y][data->algo_data.map.x] == '1')
		data->algo_data.hit = 1;
	if (data->algo_data.side == 0)
		data->algo_data.pwd = (data->algo_data.map.x - data->pl.pos.x +
				(1 - data->algo_data.step.x) / 2.0) / data->algo_data.ray_dir.x;
	else
		data->algo_data.pwd = (data->algo_data.map.y - data->pl.pos.y +
				(1 - data->algo_data.step.y) / 2.0) / data->algo_data.ray_dir.y;
}
