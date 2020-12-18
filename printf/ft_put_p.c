/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 20:27:12 by mclown            #+#    #+#             */
/*   Updated: 2020/12/17 20:29:13 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_p(void *ptr, struct s_specifier *sp)
{
	int	len;

	len = 2 + count_symbols_hex((unsigned long int)ptr);
	if (sp->width > 0)
		(*sp).width -= len;
	while (sp->width > 0 && sp->l_or_r == 1)
	{
		sp->total += mod_ft_putchar_fd(sp->filler, 1);
		sp->width--;
	}
	sp->total += mod_ft_putptr_fd(ptr, 1);
	while (sp->width > 0 && sp->l_or_r == -1)
	{
		sp->total += mod_ft_putchar_fd(sp->filler, 1);
		sp->width--;
	}
}
