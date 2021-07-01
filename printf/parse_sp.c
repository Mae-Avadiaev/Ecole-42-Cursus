/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:03:51 by mclown            #+#    #+#             */
/*   Updated: 2020/12/18 11:05:13 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_sp1(const char *string, struct s_specifier *sp, int i)
{
	if (string[i] == '-' || string[i] == '0')
	{
		if (string[i++] == '-')
			(sp->l_or_r = -1);
		else
			(sp->filler = '0');
	}
	if (string[i] == '0' || string[i] == '-')
	{
		if (string[i++] == '0')
			(sp->filler = '0');
		else
			(sp->l_or_r = -1);
	}
	return (i);
}

int		parse_sp2(const char *string, struct s_specifier *sp,
		va_list argptr, int i)
{
	while (string[i] == '0' || string[i] == '-')
		i++;
	if (string[i] == '*')
	{
		if ((sp->width = va_arg(argptr, int)) < 0)
		{
			sp->l_or_r = -1;
			sp->width *= -1;
		}
		i++;
	}
	if (sp->l_or_r == -1)
		sp->filler = ' ';
	if (ft_isdigit(string[i]))
	{
		sp->width = ft_atoi(string + i);
		while (string[i] && (ft_isdigit(string[i])))
			i++;
	}
	return (i);
}

int		parse_sp(const char *string, struct s_specifier *sp, va_list argptr)
{
	int	i;

	i = 1;
	i = parse_sp1(string, &(*sp), i);
	i = parse_sp2(string, &(*sp), argptr, i);
	if (string[i] == '.')
	{
		if (!(ft_isdigit(string[i + 1])))
			sp->prec = 0;
		i++;
	}
	if (string[i] == '*')
	{
		sp->prec = va_arg(argptr, int);
		i++;
	}
	if (ft_isdigit(string[i]))
		sp->prec = ft_atoi(string + i);
	while (string[i] && (ft_isdigit(string[i])))
		i++;
	return (i);
}
