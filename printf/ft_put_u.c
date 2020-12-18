/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 20:57:51 by mclown            #+#    #+#             */
/*   Updated: 2020/12/17 20:58:31 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	part_one_u(struct s_specifier *sp, int len)
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
}

void	part_two_u(unsigned int n, struct s_specifier *sp, int len, char *a)
{
	while (sp->prec > (len))
	{
		sp->total += mod_ft_putchar_fd('0', 1);
		sp->prec--;
	}
	if (n != 0 || sp->prec != 0)
	{
		if ((a = ft_itoa_uns(n)) == NULL)
		{
			sp->total = ERROR;
			return ;
		}
		sp->total += mod_ft_putstr_fd((a), 1);
		free(a);
	}
	while (sp->width > 0 && sp->l_or_r == -1)
	{
		sp->total += mod_ft_putchar_fd(sp->filler, 1);
		sp->width--;
	}
}

void	ft_put_u(unsigned int n, struct s_specifier *sp)
{
	int		len;
	char	*a;

	a = NULL;
	if (n == 0 && sp->prec == 0)
	{
		(len = 0);
		sp->filler = ' ';
	}
	else
	{
		if ((a = ft_itoa_uns(n)) == NULL)
		{
			sp->total = ERROR;
			return ;
		}
		(len = ft_strlen(a));
		free(a);
		a = NULL;
	}
	part_one_u(&(*sp), len);
	part_two_u(n, &(*sp), len, a);
}
