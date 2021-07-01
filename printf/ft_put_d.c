/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 19:57:59 by mclown            #+#    #+#             */
/*   Updated: 2020/12/17 20:08:57 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	part_one_d(struct s_specifier *sp, int len, int flag_minus)
{
	int total;

	total = 0;
	if (sp->width > 0)
	{
		if (sp->prec >= 0)
			(sp->prec < len) ? (sp->width -= len) :
			((*sp).width -= (*sp).prec + flag_minus);
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
	if (flag_minus == 1)
		sp->total += mod_ft_putchar_fd('-', 1);
	while (sp->width > 0 && sp->l_or_r == 1 && sp->filler == '0')
	{
		sp->total += mod_ft_putchar_fd(sp->filler, 1);
		sp->width--;
	}
}

void	part_two_d(unsigned int num, struct s_specifier *sp,
		int len, int flag_minus)
{
	char	*a;

	a = NULL;
	while (sp->prec > (len - flag_minus))
	{
		sp->total += mod_ft_putchar_fd('0', 1);
		sp->prec--;
	}
	if (num != 0 || sp->prec != 0)
	{
		if ((a = ft_itoa_uns(num)) == NULL)
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

int		count_len(int n, struct s_specifier *sp)
{
	char	*a;
	int		len;

	if ((a = ft_itoa(n)) == NULL)
	{
		sp->total = ERROR;
		return (ERROR);
	}
	(len = ft_strlen(a));
	free(a);
	return (len);
}

void	ft_put_d(int n, struct s_specifier *sp)
{
	int				len;
	int				flag_minus;
	unsigned int	num;

	num = n;
	if (n < 0)
		(num = n * -1);
	if (n == 0 && sp->prec == 0)
	{
		len = 0;
		sp->filler = ' ';
	}
	else
	{
		if ((len = count_len(n, &(*sp))) == ERROR)
			return ;
	}
	flag_minus = 0;
	if (n < 0)
		(flag_minus = 1);
	part_one_d(&(*sp), len, flag_minus);
	part_two_d(num, &(*sp), len, flag_minus);
}
