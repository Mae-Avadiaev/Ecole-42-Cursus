/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_ft_putnbr_hex_up_fd.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 10:52:11 by mclown            #+#    #+#             */
/*   Updated: 2020/12/18 10:53:54 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	mod_ft_putnbr_hex_up_fd(unsigned long int n, int fd)
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
		rem == 10 ? res[--count_syms] = 'A' : 0;
		rem == 11 ? res[--count_syms] = 'B' : 0;
		rem == 12 ? res[--count_syms] = 'C' : 0;
		rem == 13 ? res[--count_syms] = 'D' : 0;
		rem == 14 ? res[--count_syms] = 'E' : 0;
		rem == 15 ? res[--count_syms] = 'F' : 0;
		n /= 16;
	}
	count_syms = mod_ft_putstr_fd(res, fd);
	free(res);
	return (count_syms);
}
