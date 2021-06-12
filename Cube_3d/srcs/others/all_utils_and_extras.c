/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_utils_and_extras.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:21:22 by mclown            #+#    #+#             */
/*   Updated: 2021/03/18 13:57:13 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_adit_color(char *line, int k)
{
	while (ft_isdigit(line[k]))
		k++;
	while (line[k] == ' ')
		k++;
	if (line[k] != '\0')
	{
		perror("Дополнительные значения цвета");
		exit(errno);
	}
}

void	check_adit_res(char *line, int k)
{
	while (line[k] == ' ')
		k++;
	while (ft_isdigit(line[k]))
		k++;
	while (line[k] == ' ')
		k++;
	if (line[k] != '\0')
	{
		perror("Дополнительные значения разрешения");
		exit(errno);
	}
}

void	memory_error(void)
{
	perror("Ошибка памяти, GNL");
	exit(errno);
}

void	lacking_parametrs_error(void)
{
	perror("Недостаточно параметров для валидации карты");
	exit(errno);
}

int		get_color(t_data *data, int x, int y)
{
	int		color;
	char	*dst;

	dst = data->mlx.addr + (y * data->mlx.line_length +
							x * (data->mlx.bits_per_pixel / 8));
	color = *(int *)dst;
	return (color);
}
