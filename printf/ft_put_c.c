/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 19:55:40 by mclown            #+#    #+#             */
/*   Updated: 2020/12/17 19:56:59 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_c(char c, struct s_specifier *sp)
{
	if (sp->width > 0)
	{
		if (sp->prec >= 0)
			(1 > (*sp).prec) ?
			((*sp).width -= (*sp).prec) : ((*sp).width -= 1);
		else
			(*sp).width -= 1;
	}
	while (sp->width > 0 && sp->l_or_r == 1)
	{
		sp->total += mod_ft_putchar_fd(sp->filler, 1);
		sp->width--;
	}
	sp->total += mod_ft_putchar_fd(c, 1);
	while (sp->width > 0 && sp->l_or_r == -1)
	{
		sp->total += mod_ft_putchar_fd(sp->filler, 1);
		sp->width--;
	}
}
