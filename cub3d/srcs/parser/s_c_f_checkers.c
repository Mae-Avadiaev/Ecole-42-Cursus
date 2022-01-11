/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_c_f_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 15:34:56 by mclown            #+#    #+#             */
/*   Updated: 2021/03/23 21:16:36 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_for_s(char *line, t_data *data)
{
	int k;

	if (line[0] == 'S' && line[1] == ' ')
	{
		if (data->map_data.text_path[SPRITE] != NULL)
		{
			perror("Двойной ввод параметра S");
			exit(errno);
		}
		k = 2;
		while (line[k] == ' ')
			k++;
		validate_texture(data->map_data.text_path[SPRITE] =
				ft_substr(line, k, ft_strlen(line) - (k)));
		return (1);
	}
	return (0);
}

int	check_for_f_extra(char *line, t_data *data)
{
	int		k;
	char	*a;

	k = 2;
	while (line[k] == ' ')
		k++;
	if (line[k] == '\0')
		lacking_color_error();
	validate_color((data->map_data.fl_color.r =
			ft_atoi((a = ft_substr(line, k, ft_strlen(line) - k)))));
	free(a);
	while (line[k] != ',' && line[k] != '\0')
		k++;
	if (line[k] == '\0')
		lacking_color_error();
	k++;
	return (check_for_f_extra2(line, data, k));
}

int	check_for_f(char *line, t_data *data)
{
	if (line[0] == 'F' && line[1] == ' ')
	{
		if (data->map_data.fl_color.r != -1 || data->map_data.fl_color.g != -1
		|| data->map_data.fl_color.b != -1)
		{
			perror("Двойной ввод параметра F");
			exit(errno);
		}
		return (check_for_f_extra(line, data));
	}
	return (0);
}

int	check_for_c_extra(char *line, t_data *data)
{
	int		k;
	char	*a;

	k = 2;
	while (line[k] == ' ')
		k++;
	if (line[k] == '\0')
		lacking_color_error();
	validate_color((data->map_data.ceil_color.r =
			ft_atoi((a = ft_substr(line, k, ft_strlen(line) - k)))));
	free(a);
	while (line[k] != ',' && line[k] != '\0')
		k++;
	if (line[k] == '\0')
		lacking_color_error();
	k++;
	return (check_for_c_extra2(line, data, k));
}

int	check_for_c(char *line, t_data *data)
{
	if (line[0] == 'C' && line[1] == ' ')
	{
		if (data->map_data.ceil_color.r != -1
		|| data->map_data.ceil_color.g != -1
		|| data->map_data.ceil_color.b != -1)
		{
			perror("Двойной ввод параметра C");
			exit(errno);
		}
		return (check_for_c_extra(line, data));
	}
	return (0);
}
