/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:36:41 by mclown            #+#    #+#             */
/*   Updated: 2021/03/09 18:37:07 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_pl(t_pl *pl)
{
	pl->pos.x = 0;
	pl->pos.y = 0;
	pl->dir.x = 0;
	pl->dir.y = 0;
	pl->plane.x = 0;
	pl->plane.y = 0;
}

void	init_map_data(t_map_data *map_data)
{
	int i;

	i = 0;
	map_data->scr_w = 0;
	map_data->scr_h = 0;
	map_data->text_path = malloc(5 * sizeof(char*));
	map_data->text_path == NULL ? memory_error() : 0;
	while (i < 5)
	{
		map_data->text_path[i] = NULL;
		i++;
	}
	map_data->fl_color.r = -1;
	map_data->fl_color.g = -1;
	map_data->fl_color.b = -1;
	map_data->ceil_color.r = -1;
	map_data->ceil_color.g = -1;
	map_data->ceil_color.b = -1;
	map_data->map = NULL;
	map_data->map_h = 0;
	map_data->map_max_w = 0;
	map_data->fd = 0;
	map_data->head = NULL;
	map_data->isplayer = 0;
}

void	init_mlx(t_mlx *mlx)
{
	mlx->ptr = NULL;
	mlx->win = NULL;
	mlx->img = NULL;
	mlx->addr = NULL;
	mlx->bits_per_pixel = 0;
	mlx->line_length = 0;
	mlx->endian = 0;
}

void	init_algo_data(t_algo_data *algo_data)
{
	algo_data->camera_x = 0;
	algo_data->ray_dir.x = 0;
	algo_data->ray_dir.y = 0;
	algo_data->side_dist.x = 0;
	algo_data->side_dist.y = 0;
	algo_data->delta_dist.x = 0;
	algo_data->delta_dist.y = 0;
	algo_data->step.x = 0;
	algo_data->step.y = 0;
	algo_data->map.x = 0;
	algo_data->map.y = 0;
	algo_data->pwd = 0;
	algo_data->hit = 0;
	algo_data->side = 0;
	algo_data->line_h = 0;
	algo_data->draw_start = 0;
	algo_data->draw_end = 0;
}

void	init_data(t_data *data)
{
	init_pl(&(data->pl));
	init_map_data(&(data->map_data));
	init_mlx(&(data->mlx));
	init_algo_data(&(data->algo_data));
	init_key(&(data->key));
	init_txtr_data(&(data->txtr_data));
	init_sp_data(&(data->sp_data));
}
