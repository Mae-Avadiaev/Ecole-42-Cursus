/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:38:31 by mclown            #+#    #+#             */
/*   Updated: 2021/03/09 19:48:07 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_key(t_key *key)
{
	key->w = 0;
	key->s = 0;
	key->a = 0;
	key->d = 0;
	key->left = 0;
	key->right = 0;
}

void	init_txtr_data(t_txtr_data *txtr_data)
{
	int i;

	i = 0;
	txtr_data->t_arr = malloc(5 * sizeof(t_img));
	txtr_data->t_arr == NULL ? memory_error() : 0;
	while (i < 5)
	{
		txtr_data->t_arr[i].img = NULL;
		txtr_data->t_arr[i].addr = NULL;
		txtr_data->t_arr[i].line_len = 0;
		txtr_data->t_arr[i].endian = 0;
		txtr_data->t_arr[i].bpp = 0;
		txtr_data->t_arr[i].height = 0;
		txtr_data->t_arr[i].width = 0;
		i++;
	}
	txtr_data->text_num = 0;
	txtr_data->wall_x = 0;
	txtr_data->tex_x = 0;
	txtr_data->tex_y = 0;
	txtr_data->step = 0;
	txtr_data->text_pos = 0;
	txtr_data->color = 0;
}

void	init_sp_data(t_sp_data *sp_data)
{
	sp_data->num_sp = 0;
	sp_data->pair = NULL;
}

void	init_sprites(t_data *data)
{
	int sp_coun;
	int i;
	int j;

	data->sp_data.spr_arr = malloc(data->sp_data.num_sp * sizeof(t_sprite));
	data->sp_data.sp_order = malloc(data->sp_data.num_sp * sizeof(int));
	data->sp_data.sp_dist = malloc(data->sp_data.num_sp * sizeof(double));
	data->sp_data.z_buffer = malloc((data->map_data.scr_w) * sizeof(double));
	sp_coun = 0;
	i = 0;
	while (data->map_data.map[i])
	{
		j = 0;
		while (data->map_data.map[i][j])
		{
			if (data->map_data.map[i][j] == '2')
			{
				data->sp_data.spr_arr[sp_coun].x = j + 0.5;
				data->sp_data.spr_arr[sp_coun].y = i + 0.5;
				sp_coun++;
			}
			j++;
		}
		i++;
	}
}

void	init_textures(t_data *data)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		data->txtr_data.t_arr[i].img = mlx_png_file_to_image(
				data->mlx.ptr,
				data->map_data.text_path[i],
				&data->txtr_data.t_arr[i].width,
				&data->txtr_data.t_arr[i].height);
		data->txtr_data.t_arr[i].addr = mlx_get_data_addr(
				data->txtr_data.t_arr[i].img,
				&(data->txtr_data.t_arr[i].bpp),
				&(data->txtr_data.t_arr[i].line_len),
				&(data->txtr_data.t_arr[i].endian));
		i++;
	}
}
