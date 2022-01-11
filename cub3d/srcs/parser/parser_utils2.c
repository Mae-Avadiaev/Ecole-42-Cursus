/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 21:12:14 by mclown            #+#    #+#             */
/*   Updated: 2021/03/23 21:14:51 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	lacking_color_error(void)
{
	perror("Недостаточно параметров цвета");
	exit(errno);
}

int		check_for_f_extra2(char *line, t_data *data, int k)
{
	char	*a;

	validate_color((data->map_data.fl_color.g =
			ft_atoi((a = ft_substr(line, k, ft_strlen(line) - (k))))));
	free(a);
	while (line[k] != ',' && line[k] != '\0')
		k++;
	if (line[k] == '\0')
		lacking_color_error();
	k++;
	validate_color((data->map_data.fl_color.b =
			ft_atoi((a = ft_substr(line, k, ft_strlen(line) - (k))))));
	free(a);
	check_adit_color(line, k);
	return (1);
}

int		check_for_c_extra2(char *line, t_data *data, int k)
{
	char	*a;

	validate_color((data->map_data.ceil_color.g =
			ft_atoi((a = ft_substr(line, k, ft_strlen(line) - (k))))));
	free(a);
	while (line[k] != ',' && line[k] != '\0')
		k++;
	if (line[k] == '\0')
		lacking_color_error();
	k++;
	validate_color((data->map_data.ceil_color.b =
			ft_atoi((a = ft_substr(line, k, ft_strlen(line) - (k))))));
	free(a);
	check_adit_color(line, k);
	return (1);
}
