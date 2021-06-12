/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:16:02 by mclown            #+#    #+#             */
/*   Updated: 2021/03/15 18:39:46 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*add_spaces(char *content, t_data *data)
{
	char	*res;
	int		i;
	int		len_content;

	res = ft_calloc(data->map_data.map_max_w + 1, sizeof(char));
	if (res == NULL)
		memory_error();
	len_content = ft_strlen(content);
	i = 0;
	while (i < len_content)
	{
		res[i] = content[i];
		i++;
	}
	while (i < data->map_data.map_max_w)
	{
		res[i] = ' ';
		i++;
	}
	return (res);
}

char	**make_map(t_list **head, int size, t_data *data)
{
	char	**map;
	int		i;
	t_list	*tmp;

	map = ft_calloc(size + 1, sizeof(char *));
	map == NULL ? memory_error() : 0;
	i = -1;
	tmp = *head;
	while (((char *)(tmp->content))[0] == '\0')
		tmp = tmp->next;
	while (tmp)
	{
		if (((char *)(tmp->content))[0] != '\0')
		{
			map[++i] = add_spaces(tmp->content, data);
			data->map_data.map_h++;
		}
		else
		{
			perror("Карта не валидна, перенос в карте");
			exit(errno);
		}
		tmp = tmp->next;
	}
	return (map);
}

void	ns_player_checker(t_data *data, char sym)
{
	if (sym == 'N')
	{
		data->pl.dir.x = 0;
		data->pl.dir.y = -1;
		data->pl.plane.x = -0.66;
		data->pl.plane.y = 0;
	}
	if (sym == 'S')
	{
		data->pl.dir.x = 0;
		data->pl.dir.y = 1;
		data->pl.plane.x = 0.66;
		data->pl.plane.y = 0;
	}
}

void	we_player_checker(t_data *data, char sym)
{
	if (sym == 'W')
	{
		data->pl.dir.x = -1;
		data->pl.dir.y = 0;
		data->pl.plane.x = 0;
		data->pl.plane.y = 0.66;
	}
	if (sym == 'E')
	{
		data->pl.dir.x = 1;
		data->pl.dir.y = 0;
		data->pl.plane.x = 0;
		data->pl.plane.y = -0.66;
	}
}

void	find_pl_and_cn_spr(t_data *data, t_map_data map_data)
{
	int i;
	int j;

	i = 0;
	while (data->map_data.map[i])
	{
		j = 0;
		while (data->map_data.map[i][j])
		{
			if (map_data.map[i][j] == 'N' || map_data.map[i][j] == 'S' ||
				map_data.map[i][j] == 'W' || map_data.map[i][j] == 'E')
			{
				data->pl.pos.x = j + 0.5;
				data->pl.pos.y = i + 0.5;
				ns_player_checker(data, data->map_data.map[i][j]);
				we_player_checker(data, data->map_data.map[i][j]);
				map_data.map[i][j] = '0';
			}
			else if (data->map_data.map[i][j] == '2')
				data->sp_data.num_sp++;
			j++;
		}
		i++;
	}
}
