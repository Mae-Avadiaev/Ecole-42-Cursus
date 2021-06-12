/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parametr_validators.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:49:11 by mclown            #+#    #+#             */
/*   Updated: 2021/03/09 19:55:12 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	validate_texture(char *texture)
{
	int	n;

	n = ft_strlen(texture) - 1;
	if (texture[n - 2] != 'p' || texture[n - 1] != 'n' || texture[n] != 'g')
	{
		perror("Неверный формат текстуры (должен быть .png)");
		exit(errno);
	}
	if (open(texture, O_RDONLY) == -1)
	{
		perror("Невалидная текстура");
		exit(errno);
	}
}

void	validate_r(int resolution, t_data *data)
{
	int	real_w_screen;
	int	real_h_screen;

	if (resolution <= 0)
	{
		perror("Слишком большой или отсутвуйщий параметр разрешения");
		exit(errno);
	}
	mlx_get_screen_size(data->mlx.ptr, &real_w_screen, &real_h_screen);
	if (data->map_data.scr_w > real_w_screen)
		data->map_data.scr_w = real_w_screen;
	if (data->map_data.scr_h > real_h_screen)
		data->map_data.scr_h = real_h_screen;
}

void	validate_color(int color)
{
	if (color < 0 || color > 255)
	{
		perror("Невалидный цвет потолка или пола");
		exit(errno);
	}
}
