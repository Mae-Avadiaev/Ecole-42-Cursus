/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 21:40:02 by mclown            #+#    #+#             */
/*   Updated: 2021/03/09 21:44:09 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		all_hook(t_data *data)
{
	move(data);
	draw_fl_and_ce(data->map_data.fl_color, data->map_data.ceil_color, data);
	cast_rays(data);
	cast_sprites(data);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->mlx.img, 0, 0);
	mlx_do_sync(data->mlx.ptr);
	return (0);
}

void	init_parse_start(t_data *data, char *argv1)
{
	init_data(data);
	data->mlx.ptr = mlx_init();
	if (argv1[ft_strlen(argv1) - 3] != 'c' && argv1[ft_strlen(argv1) - 2] != 'u'
	&& argv1[ft_strlen(argv1) - 1] != 'b')
	{
		perror("Неверное расширение карты (должно быть .cub)");
		exit(errno);
	}
	parse_params(data, argv1);
	if (data->map_data.ceil_color.r == -1 || data->map_data.ceil_color.g == -1
	|| data->map_data.ceil_color.b == -1 || data->map_data.fl_color.r == -1
	|| data->map_data.fl_color.g == -1 || data->map_data.fl_color.b == -1)
	{
		perror("Не хватает параметроа цвета");
		exit(errno);
	}
	parse_map(data);
	if (data->pl.pos.x == 0 && data->pl.pos.y == 0)
	{
		perror("Нет игрока на карте");
		exit(errno);
	}
	init_textures(data);
	init_sprites(data);
	start_mlx(data);
}

int		simple_exit(void)
{
	exit(0);
}

void	mlx_loops_and_hooks(t_data *data)
{
	mlx_loop_hook(data->mlx.ptr, all_hook, data);
	mlx_hook(data->mlx.win, 2, 1L << 0, &key_pressed, data);
	mlx_hook(data->mlx.win, 3, 1L << 1, &key_released, data);
	mlx_hook(data->mlx.win, 17, 0, &simple_exit, data);
	mlx_loop(data->mlx.ptr);
}
