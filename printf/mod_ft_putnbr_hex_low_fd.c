/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_ft_putnbr_hex_low_fd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 10:47:17 by mclown            #+#    #+#             */
/*   Updated: 2020/12/18 10:51:36 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_symbols_hex(unsigned long int n)
{
	int	count_syms;

	count_syms = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		count_syms++;
		n /= 16;
	}
	return (count_syms);
}

int	mod_ft_putnbr_hex_low_fd(unsigned long int n, int fd)
{
	unsigned long int	rem;
	char				*res;
	int					count_syms;

	count_syms = count_symbols_hex(n);
	if (!(res = (char *)malloc((count_syms * sizeof(char)) + 1)))
		return (INT_MIN);
	res[count_syms] = '\0';
	(n == 0) ? res[count_syms - 1] = '0' : 0;
	while (n != 0)
	{
		rem = n % 16;
		rem < 10 ? res[--count_syms] = rem + 48 : 0;
		rem == 10 ? res[--count_syms] = 'a' : 0;
		rem == 11 ? res[--count_syms] = 'b' : 0;
		rem == 12 ? res[--count_syms] = 'c' : 0;
		rem == 13 ? res[--count_syms] = 'd' : 0;
		rem == 14 ? res[--count_syms] = 'e' : 0;
		rem == 15 ? res[--count_syms] = 'f' : 0;
		n /= 16;
	}
	count_syms = mod_ft_putstr_fd(res, fd);
	free(res);
	return (count_syms);
}
