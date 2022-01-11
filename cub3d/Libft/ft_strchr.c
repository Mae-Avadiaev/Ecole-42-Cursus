/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 22:00:49 by mclown            #+#    #+#             */
/*   Updated: 2020/11/11 22:01:07 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	char		c1;

	i = 0;
	c1 = (char)c;
	if (c1 == '\0')
	{
		while (s[i] != '\0')
			i++;
		return ((char *)(s + i));
	}
	while (s[i] != '\0')
	{
		if (s[i] == c1)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
