/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_sprites_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:54:50 by mclown            #+#    #+#             */
/*   Updated: 2021/03/10 18:02:38 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	cs_part1(t_data *data, int sp_coun)
{
	while (sp_coun < data->sp_data.num_sp)
	{
		data->sp_data.sp_order[sp_coun] = sp_coun;
		data->sp_data.sp_dist[sp_coun] =
				((data->pl.pos.x - data->sp_data.spr_arr[sp_coun].x)
				* (data->pl.pos.x - data->sp_data.spr_arr[sp_coun].x)
				+ (data->pl.pos.y - data->sp_data.spr_arr[sp_coun].y)
				* (data->pl.pos.y - data->sp_data.spr_arr[sp_coun].y));
		sp_coun++;
	}
}

void	cs_part2(t_data *data, int sp_coun)
{
	data->sp_data.cur_sp.x = data->sp_data.spr_arr
		[data->sp_data.sp_order[sp_coun]].x - data->pl.pos.x;
	data->sp_data.cur_sp.y = data->sp_data.spr_arr
		[data->sp_data.sp_order[sp_coun]].y - data->pl.pos.y;
	data->sp_data.inv_det = 1.0 / (data->pl.plane.x
		* data->pl.dir.y - data->pl.dir.x * data->pl.plane.y);
	data->sp_data.transform.x = data->sp_data.inv_det * (data->pl.dir.y *
		data->sp_data.cur_sp.x - data->pl.dir.x * data->sp_data.cur_sp.y);
	data->sp_data.transform.y = data->sp_data.inv_det * (-data->pl.plane.y
		* data->sp_data.cur_sp.x + data->pl.plane.x * data->sp_data.cur_sp.y);
	data->sp_data.sp_screen_x = (int)((data->map_data.scr_w / 2.0)
		* (1 + data->sp_data.transform.x / data->sp_data.transform.y));
	data->sp_data.sp_height = abs((int)(data->map_data.scr_h
								/ (data->sp_data.transform.y)));
	data->sp_data.draw_start.y = -data->sp_data.sp_height
								/ 2 + data->map_data.scr_h / 2;
	if (data->sp_data.draw_start.y < 0)
		data->sp_data.draw_start.y = 0;
}

void	cs_part3(t_data *data)
{
	data->sp_data.draw_end.y = data->sp_data.sp_height
						/ 2 + data->map_data.scr_h / 2;
	if (data->sp_data.draw_end.y >= data->map_data.scr_h)
		data->sp_data.draw_end.y = data->map_data.scr_h - 1;
	data->sp_data.sp_width = abs((int)(data->map_data.scr_h
						/ (data->sp_data.transform.y)));
	data->sp_data.draw_start.x = -data->sp_data.sp_width
						/ 2 + data->sp_data.sp_screen_x;
	if (data->sp_data.draw_start.x < 0)
		data->sp_data.draw_start.x = 0;
	data->sp_data.draw_end.x = data->sp_data.sp_width
						/ 2 + data->sp_data.sp_screen_x;
	if (data->sp_data.draw_end.x >= data->map_data.scr_w)
		data->sp_data.draw_end.x = data->map_data.scr_w - 1;
}

void	cs_part4(t_data *data, int stripe, int y)
{
	data->sp_data.tex.x = (int)(256 * (stripe - (-data->sp_data.sp_width
		/ 2 + data->sp_data.sp_screen_x)) * data->txtr_data.t_arr[SPRITE].width
		/ data->sp_data.sp_width) / 256;
	if (data->sp_data.transform.y > 0 && stripe > 0
		&& stripe < data->map_data.scr_w
		&& data->sp_data.transform.y < data->sp_data.z_buffer[stripe])
	{
		y = data->sp_data.draw_start.y;
		while (y < data->sp_data.draw_end.y)
		{
			data->sp_data.d = (y) * 256 - data->map_data.scr_h
							* 128 + data->sp_data.sp_height * 128;
			data->sp_data.tex.y = ((data->sp_data.d * data->txtr_data.t_arr
						[SPRITE].height) / data->sp_data.sp_height) / 256;
			data->sp_data.color = *(unsigned int *)
				(data->txtr_data.t_arr[SPRITE].addr
				+ (data->sp_data.tex.y * data->txtr_data.t_arr[SPRITE].line_len
				+ data->sp_data.tex.x *
				(data->txtr_data.t_arr[SPRITE].bpp / 8)));
			if ((data->sp_data.color & 0x00FFFFFF) != 0)
				my_mlx_pixel_put(data, data->map_data.scr_w
						- stripe - 1, y, data->sp_data.color);
			y++;
		}
	}
}
