/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:07:41 by mclown            #+#    #+#             */
/*   Updated: 2021/03/15 18:38:43 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_isstrallsym(const char *str, int sym)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != sym)
			return (0);
		i++;
	}
	return (1);
}

void	check_for_space_extra(t_map_data *map_data, int i, int j, int error)
{
	if (j != 0)
	{
		(map_data->map[i][j - 1] == '0'
		|| map_data->map[i][j - 1] == '2') ? error = 1 : 0;
	}
	if (j != (int)(ft_strlen(map_data->map[i]) - 1))
	{
		(map_data->map[i][j + 1] == '0'
		|| map_data->map[i][j + 1] == '2') ? error = 1 : 0;
	}
	if (error)
	{
		perror("Карта не валидна, открытое пространство");
		exit(errno);
	}
	map_data->map[i][j] = '1';
}

void	check_for_space(t_map_data *map_data, int i, int j)
{
	int	error;

	error = 0;
	if (map_data->map[i][j] == ' ')
	{
		if (i != 0)
		{
			(map_data->map[i - 1][j] == '0'
			|| map_data->map[i - 1][j] == '2') ? error = 1 : 0;
		}
		if (i != map_data->map_h - 1)
		{
			(map_data->map[i + 1][j] == '0'
			|| map_data->map[i + 1][j] == '2') ? error = 1 : 0;
		}
		check_for_space_extra(map_data, i, j, error);
	}
}

void	check_for_invalid(t_map_data *map_data, int i, int j)
{
	if (!ft_strchr(VALID_MAP_CHARACTERS, map_data->map[i][j]))
	{
		perror("Невалидный символ в карте");
		exit(errno);
	}
	if (j == 0 || map_data->map[i][j + 1] == '\0')
	{
		if (map_data->map[i][j] != '1')
		{
			perror("Карта не валидна, открытое пространство");
			exit(errno);
		}
	}
	if (ft_strchr(PLAYER_CHARACTERS, map_data->map[i][j]))
	{
		if (map_data->isplayer == 0)
			map_data->isplayer = 1;
		else if (map_data->isplayer == 1)
		{
			perror("Два игрока на карте");
			exit(errno);
		}
	}
}

void	validate_map(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data->map_data.map[i])
	{
		j = 0;
		while (data->map_data.map[i][j])
		{
			check_for_space(&data->map_data, i, j);
			check_for_invalid(&data->map_data, i, j);
			j++;
		}
		if (i == 0 || i == data->map_data.map_h - 1)
		{
			if (!ft_isstrallsym(data->map_data.map[i], '1'))
			{
				perror("Карта не валидна, открытое пространство");
				exit(errno);
			}
		}
		i++;
	}
}
