/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_ft_putptr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:01:10 by mclown            #+#    #+#             */
/*   Updated: 2020/12/18 11:01:16 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	mod_ft_putptr_fd(void *ptr, int fd)
{
	unsigned long int num;

	num = (unsigned long int)ptr;
	mod_ft_putstr_fd("0x", fd);
	return (mod_ft_putnbr_hex_low_fd(num, fd) + 2);
}
