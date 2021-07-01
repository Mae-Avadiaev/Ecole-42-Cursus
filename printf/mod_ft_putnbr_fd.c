/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_ft_putnbr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 10:46:17 by mclown            #+#    #+#             */
/*   Updated: 2020/12/18 10:46:36 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	mod_ft_putnbr_fd(int n, int fd)
{
	int				total;

	total = 0;
	total += mod_ft_putstr_fd(ft_itoa(n), fd);
	return (total);
}
