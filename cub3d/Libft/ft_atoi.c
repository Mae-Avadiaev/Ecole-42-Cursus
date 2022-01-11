/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:58:34 by mclown            #+#    #+#             */
/*   Updated: 2020/11/12 14:08:27 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi(const char *str)
{
	long int	res;
	size_t		i;
	int			minus_sign;

	res = 0;
	i = 0;
	minus_sign = 1;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\f'
			|| str[i] == '\r' || str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			minus_sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i++] - 48);
		if (res > 2147483647 && minus_sign == 1)
			return (-1);
		if (res > 2147483648 && minus_sign == -1)
			return (0);
	}
	return ((int)(res * minus_sign));
}
