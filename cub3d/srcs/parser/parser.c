/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:18:27 by mclown            #+#    #+#             */
/*   Updated: 2021/03/15 18:36:58 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	parse_map(t_data *data)
{
	t_list	*head;
	char	*line;
	int		len;
	int		gnl;

	line = NULL;
	head = NULL;
	while ((gnl = get_next_line(data->map_data.fd, &line)))
	{
		if (gnl == -1)
		{
			perror("Ошибка памяти, GNL");
			exit(errno);
		}
		ft_lstadd_back(&head, ft_lstnew(line));
		len = ft_strlen(line);
		if (len > data->map_data.map_max_w)
			data->map_data.map_max_w = len;
	}
	ft_lstadd_back(&head, ft_lstnew(line));
	close(data->map_data.fd);
	data->map_data.map = make_map(&head, ft_lstsize(head), data);
	validate_map(data);
	find_pl_and_cn_spr(data, data->map_data);
	data->map_data.head = head;
}

int		checkers(char *line, t_data *data)
{
	int res;

	res = 0;
	check_for_r(line, data) == 1 ? res = 1 : 0;
	check_for_no(line, data) == 1 ? res = 1 : 0;
	check_for_so(line, data) == 1 ? res = 1 : 0;
	check_for_we(line, data) == 1 ? res = 1 : 0;
	check_for_ea(line, data) == 1 ? res = 1 : 0;
	check_for_s(line, data) == 1 ? res = 1 : 0;
	check_for_f(line, data) == 1 ? res = 1 : 0;
	check_for_c(line, data) == 1 ? res = 1 : 0;
	if (res == 0 && ft_strncmp(line, "\0", 1))
	{
		perror("Незнакомый параметр в карте");
		exit(errno);
	}
	return (res);
}

void	parse_params(t_data *data, char *argv)
{
	int		found;
	int		fd;
	char	*line;
	int		gnl;

	line = NULL;
	found = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("Такой карты не существует");
		exit(errno);
	}
	while (found < 8)
	{
		if (!(gnl = get_next_line(fd, &line)))
			break ;
		if (gnl == -1)
			memory_error();
		found += checkers(line, data);
		free(line);
	}
	if (found != 8)
		lacking_parametrs_error();
	data->map_data.fd = fd;
}
