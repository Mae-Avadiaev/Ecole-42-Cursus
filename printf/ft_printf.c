/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:57:47 by mclown            #+#    #+#             */
/*   Updated: 2020/12/17 19:02:26 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_spec(struct s_specifier *sp)
{
	sp->prec = -1;
	sp->filler = ' ';
	sp->l_or_r = 1;
	sp->width = 0;
}

int		proccesor(const char *string, struct s_specifier *sp, va_list argptr)
{
	if (*string == 'd' || *string == 'i')
		ft_put_d(va_arg(argptr, int), &(*sp));
	else if (*string == 'c')
		ft_put_c(va_arg(argptr, int), &(*sp));
	else if (*string == 's')
		ft_put_s(va_arg(argptr, char*), &(*sp));
	else if (*string == 'u')
		ft_put_u(va_arg(argptr, unsigned int), &(*sp));
	else if (*string == 'x')
		ft_put_x(va_arg(argptr, unsigned int), &(*sp));
	else if (*string == 'X')
		ft_put_x_up(va_arg(argptr, unsigned int), &(*sp));
	else if (*string == 'p')
		ft_put_p(va_arg(argptr, void *), &(*sp));
	else if (*string == '%')
		ft_put_c('%', &(*sp));
	return (sp->total);
}

int		ft_printf(const char *string, ...)
{
	va_list				argptr;
	struct s_specifier	sp;

	va_start(argptr, string);
	sp.total = 0;
	while (*string)
	{
		if (*string != '%')
		{
			sp.total += mod_ft_putchar_fd(*string, 1);
			string++;
		}
		else
		{
			initialize_spec(&sp);
			string += parse_sp(string, &sp, argptr);
			if (proccesor(string, &sp, argptr) == ERROR)
				return (ERROR);
			*string ? string++ : 0;
		}
	}
	va_end(argptr);
	return (sp.total);
}
