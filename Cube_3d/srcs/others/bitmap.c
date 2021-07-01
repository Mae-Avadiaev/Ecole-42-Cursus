/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 21:49:57 by mclown            #+#    #+#             */
/*   Updated: 2021/03/18 13:50:49 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_in_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

void	header(int fd, int file_size, t_data *data)
{
	int				i;
	int				tmp;
	unsigned char	file_header[54];

	i = 0;
	while (i < 54)
		file_header[i++] = (unsigned char)(0);
	file_header[0] = (unsigned char)('B');
	file_header[1] = (unsigned char)('M');
	set_in_char(file_header + 2, file_size);
	file_header[10] = (unsigned char)(54);
	file_header[14] = (unsigned char)(40);
	tmp = data->map_data.scr_w;
	set_in_char(file_header + 18, tmp);
	tmp = data->map_data.scr_h;
	set_in_char(file_header + 22, tmp);
	file_header[26] = (unsigned char)(1);
	file_header[28] = (unsigned char)(32);
	write(fd, file_header, 54);
}

void	write_pixels(int fd, t_data *data)
{
	int	i;
	int	j;
	int	color;

	i = data->map_data.scr_h - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < data->map_data.scr_w)
		{
			color = get_color(data, j, i);
			write(fd, &color, 4);
			j++;
		}
		i--;
	}
}

void	make_screenshot(t_data *data, char *name)
{
	int	file_size;
	int	fd;

	file_size = 54 + ((4 * data->map_data.scr_w) * data->map_data.scr_h);
	fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 066);
	header(fd, file_size, data);
	write_pixels(fd, data);
}

void	make_screenshot_good_bye(t_data *data, char *name)
{
	draw_fl_and_ce(data->map_data.fl_color, data->map_data.ceil_color, data);
	cast_rays(data);
	cast_sprites(data);
	make_screenshot(data, name);
	exit(0);
}
