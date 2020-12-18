/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 10:40:47 by mclown            #+#    #+#             */
/*   Updated: 2020/12/18 10:43:50 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	part_one_x_up(struct s_specifier *sp, int len)
{
	if (sp->width > 0)
	{
		if (sp->prec >= 0)
			(sp->prec < len) ? (sp->width -= len) : ((*sp).width -= (*sp).prec);
		else
			(*sp).width -= len;
	}
	if (sp->prec >= 0 && sp->width)
		sp->filler = ' ';
	while (sp->width > 0 && sp->l_or_r == 1 && sp->filler == ' ')
	{
		sp->total += mod_ft_putchar_fd(sp->filler, 1);
		sp->width--;
	}
	while (sp->width > 0 && sp->l_or_r == 1 && sp->filler == '0')
	{
		sp->total += mod_ft_putchar_fd(sp->filler, 1);
		sp->width--;
	}
	while (sp->prec > (len))
	{
		sp->total += mod_ft_putchar_fd('0', 1);
		sp->prec--;
	}
}

void	ft_put_x_up(unsigned int n, struct s_specifier *sp)
{
	int	len;

	if (n == 0 && sp->prec == 0)
		(len = 0);
	else
		(len = count_symbols_hex(n));
	part_one_x_up(&(*sp), len);
	(n == 0 && sp->prec == 0) ? 0 :
		(sp->total += mod_ft_putnbr_hex_up_fd(n, 1));
	while (sp->width > 0 && sp->l_or_r == -1)
	{
		sp->total += mod_ft_putchar_fd(sp->filler, 1);
		sp->width--;
	}
}
