/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:46:25 by mclown            #+#    #+#             */
/*   Updated: 2021/03/10 17:53:47 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	cr_part4(t_data *data)
{
	data->algo_data.line_h = (int)(data->map_data.scr_h / data->algo_data.pwd);
	data->algo_data.draw_start = -(data->algo_data.line_h)
		/ 2 + data->map_data.scr_h / 2;
	if (data->algo_data.draw_start < 0)
		data->algo_data.draw_start = 0;
	data->algo_data.draw_end = data->algo_data.line_h
		/ 2 + data->map_data.scr_h / 2;
	if (data->algo_data.draw_end >= data->map_data.scr_h)
		data->algo_data.draw_end = data->map_data.scr_h - 1;
}

void	cr_part5(t_data *data)
{
	if (data->algo_data.side == 0)
		data->txtr_data.wall_x = data->pl.pos.y
			+ data->algo_data.pwd * data->algo_data.ray_dir.y;
	else
		data->txtr_data.wall_x = data->pl.pos.x + data->algo_data.pwd
			* data->algo_data.ray_dir.x;
	data->txtr_data.wall_x -= floor((data->txtr_data.wall_x));
	data->txtr_data.tex_x = (int)(data->txtr_data.wall_x *
			(double)(data->txtr_data.t_arr[data->txtr_data.text_num].width));
	if (data->algo_data.side == 0 && data->algo_data.ray_dir.x > 0)
		data->txtr_data.tex_x = data->txtr_data.t_arr
			[data->txtr_data.text_num].width - data->txtr_data.tex_x - 1;
	if (data->algo_data.side == 1 && data->algo_data.ray_dir.y < 0)
		data->txtr_data.tex_x = data->txtr_data.t_arr
			[data->txtr_data.text_num].width - data->txtr_data.tex_x - 1;
	data->txtr_data.step = 1.0 * data->txtr_data.t_arr
		[data->txtr_data.text_num].height / data->algo_data.line_h;
	data->txtr_data.text_pos =
			(data->algo_data.draw_start - data->map_data.scr_h
			/ 2 + data->algo_data.line_h / 2) *
			data->txtr_data.step;
}

void	cr_part6(t_data *data, int x)
{
	int y;

	y = data->algo_data.draw_start;
	while (y < data->algo_data.draw_end)
	{
		data->txtr_data.tex_y = (int)data->txtr_data.text_pos
			& (data->txtr_data.t_arr[data->txtr_data.text_num].height - 1);
		data->txtr_data.text_pos += data->txtr_data.step;
		data->txtr_data.color = *(unsigned int *)
			(data->txtr_data.t_arr[data->txtr_data.text_num].addr
			+ (data->txtr_data.tex_y
			* data->txtr_data.t_arr[data->txtr_data.text_num].line_len
			+ data->txtr_data.tex_x
			* (data->txtr_data.t_arr[data->txtr_data.text_num].bpp / 8)));
		my_mlx_pixel_put(data, data->map_data.scr_w - x - 1, y,
				data->txtr_data.color);
		y++;
	}
	data->sp_data.z_buffer[x] = data->algo_data.pwd;
}
