/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 20:43:29 by mclown            #+#    #+#             */
/*   Updated: 2020/12/17 20:46:45 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_s(char *s, struct s_specifier *sp)
{
	size_t	i;
	int		len;

	(s == NULL) ? s = "(null)" : 0;
	i = 0;
	len = ft_strlen(s);
	if (sp->width > 0)
	{
		if (sp->prec >= 0)
			len > sp->prec ? sp->width -= sp->prec : (sp->width -= len);
		else
			(*sp).width -= len;
	}
	while (sp->width > 0 && sp->l_or_r == 1)
	{
		sp->total += mod_ft_putchar_fd(sp->filler, 1);
		sp->width--;
	}
	while (s[i] != '\0' && sp->prec--)
		sp->total += mod_ft_putchar_fd(s[i++], 1);
	while (sp->width > 0 && sp->l_or_r == -1)
	{
		sp->total += mod_ft_putchar_fd(sp->filler, 1);
		sp->width--;
	}
}
