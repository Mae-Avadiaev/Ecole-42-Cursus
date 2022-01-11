/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:27:17 by mclown            #+#    #+#             */
/*   Updated: 2021/03/10 18:29:23 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		move(t_data *data)
{
	double	movespeed;
	double	rotspeed;

	movespeed = 0.1;
	rotspeed = 0.1;
	if (data->key.w == 1 || data->key.s == 1)
		key_w_or_key_s(data, movespeed);
	if (data->key.a == 1 || data->key.d == 1)
		key_a_or_key_d(data, movespeed);
	if (data->key.left == 1 || data->key.right == 1)
		key_left_or_key_right(data->key,
				&(data->pl), data->algo_data, rotspeed);
	return (0);
}

void	draw_fl_and_ce(t_color fl, t_color ce, t_data *data)
{
	int		x;
	size_t	ceil_color;
	size_t	fl_color;
	int		dr;
	int		dr1;

	x = 0;
	while (x < data->map_data.scr_w)
	{
		ceil_color = create_trgb(0, ce.r, ce.g, ce.b);
		dr = 0;
		while (dr <= data->map_data.scr_h / 2)
		{
			my_mlx_pixel_put(data, x, dr, ceil_color);
			dr++;
		}
		fl_color = create_trgb(0, fl.r, fl.g, fl.b);
		dr1 = data->map_data.scr_h / 2;
		while (dr1 <= data->map_data.scr_h - 1)
		{
			my_mlx_pixel_put(data, x, dr1, fl_color);
			dr1++;
		}
		x++;
	}
}

void	cast_rays(t_data *data)
{
	int	x;

	x = 0;
	while (x < data->map_data.scr_w)
	{
		cr_part1(data, x);
		cr_part2(data);
		while (data->algo_data.hit == 0)
		{
			cr_part3(data);
			cr_part4(data);
		}
		def_texture(data);
		cr_part5(data);
		cr_part6(data, x);
		x++;
	}
}

void	cast_sprites(t_data *data)
{
	int sp_coun;
	int stripe;
	int y;

	y = 0;
	sp_coun = 0;
	cs_part1(data, sp_coun);
	sort_sprites(&(data->sp_data));
	sp_coun = 0;
	while (sp_coun < data->sp_data.num_sp)
	{
		cs_part2(data, sp_coun);
		cs_part3(data);
		stripe = data->sp_data.draw_start.x;
		while (stripe < data->sp_data.draw_end.x)
		{
			cs_part4(data, stripe, y);
			stripe++;
		}
		sp_coun++;
	}
}
