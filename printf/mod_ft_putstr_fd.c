/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_ft_putstr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:02:05 by mclown            #+#    #+#             */
/*   Updated: 2020/12/18 11:03:14 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	mod_ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	int		total;

	i = 0;
	total = 0;
	while (s[i] != '\0')
	{
		total += mod_ft_putchar_fd(s[i], fd);
		i++;
	}
	return (total);
}
