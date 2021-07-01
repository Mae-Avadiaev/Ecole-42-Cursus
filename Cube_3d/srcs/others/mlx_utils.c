/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 21:45:19 by mclown            #+#    #+#             */
/*   Updated: 2021/03/09 21:49:09 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->mlx.addr + (y * data->mlx.line_length
			+ x * (data->mlx.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	start_mlx(t_data *data)
{
	data->mlx.win = mlx_new_window(data->mlx.ptr,
			data->map_data.scr_w, data->map_data.scr_h, "Cub3d");
	data->mlx.img = mlx_new_image(data->mlx.ptr,
			data->map_data.scr_w, data->map_data.scr_h);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img,
			&data->mlx.bits_per_pixel, &data->mlx.line_length,
										&data->mlx.endian);
}
