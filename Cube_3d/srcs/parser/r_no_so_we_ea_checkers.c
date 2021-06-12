/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_no_so_we_ea_checkers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 15:17:24 by mclown            #+#    #+#             */
/*   Updated: 2021/03/09 19:58:40 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_for_r(char *line, t_data *data)
{
	int		k;
	char	*a;

	if (line[0] == 'R' && line[1] == ' ')
	{
		if (data->map_data.scr_w != 0 && data->map_data.scr_h != 0)
		{
			perror("Двойной ввод параметра R");
			exit(errno);
		}
		k = 2;
		while (line[k] == ' ')
			k++;
		validate_r((data->map_data.scr_w = ft_atoi(
				(a = ft_substr(line, k, ft_strlen(line) - (k))))), data);
		free(a);
		while (line[k] >= '0' && line[k] <= '9')
			k++;
		validate_r((data->map_data.scr_h = ft_atoi(
					(a = ft_substr(line, k, ft_strlen(line) - (k))))), data);
		free(a);
		check_adit_res(line, k);
		return (1);
	}
	return (0);
}

int	check_for_no(char *line, t_data *data)
{
	int k;

	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
	{
		if (data->map_data.text_path[NORTH] != NULL)
		{
			perror("Двойной ввод параметра NO");
			exit(errno);
		}
		k = 3;
		while (line[k] == ' ')
			k++;
		validate_texture((data->map_data.text_path[NORTH] =
				ft_substr(line, k, ft_strlen(line) - (k))));
		return (1);
	}
	return (0);
}

int	check_for_so(char *line, t_data *data)
{
	int k;

	if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
	{
		if (data->map_data.text_path[SOUTH] != NULL)
		{
			perror("Двойной ввод параметра SO");
			exit(errno);
		}
		k = 3;
		while (line[k] == ' ')
			k++;
		validate_texture((data->map_data.text_path[SOUTH] =
				ft_substr(line, k, ft_strlen(line) - (k))));
		return (1);
	}
	return (0);
}

int	check_for_we(char *line, t_data *data)
{
	int k;

	if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
	{
		if (data->map_data.text_path[WEST] != NULL)
		{
			perror("Двойной ввод параметра WE");
			exit(errno);
		}
		k = 3;
		while (line[k] == ' ')
			k++;
		validate_texture((data->map_data.text_path[WEST] =
				ft_substr(line, k, ft_strlen(line) - (k))));
		return (1);
	}
	return (0);
}

int	check_for_ea(char *line, t_data *data)
{
	int k;

	if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
	{
		if (data->map_data.text_path[EAST] != NULL)
		{
			perror("Двойной ввод параметра EA");
			exit(errno);
		}
		k = 3;
		while (line[k] == ' ')
			k++;
		validate_texture((data->map_data.text_path[EAST] =
				ft_substr(line, k, ft_strlen(line) - (k))));
		return (1);
	}
	return (0);
}
