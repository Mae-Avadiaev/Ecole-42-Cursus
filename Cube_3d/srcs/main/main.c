/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:28:51 by mclown            #+#    #+#             */
/*   Updated: 2021/03/10 13:28:55 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
	{
		perror("Не переданна карта");
		exit(errno);
	}
	init_parse_start(&data, argv[1]);
	if (argc == 3)
	{
		if (!ft_strncmp(argv[2], "--save", 10))
			make_screenshot_good_bye(&data, "cub3d.bmp");
	}
	if (argc > 2)
	{
		perror("Непонятный аргумент");
		exit(errno);
	}
	mlx_loops_and_hooks(&data);
	return (0);
}
