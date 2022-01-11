/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 22:01:40 by mclown            #+#    #+#             */
/*   Updated: 2020/11/11 22:02:57 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	c1;
	size_t			i;
	char			*pointer;

	i = 0;
	pointer = (char *)NULL;
	c1 = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == c1)
			pointer = (char *)(&s[i]);
		i++;
	}
	if (c1 == '\0')
		return ((char *)(&s[i]));
	if (pointer)
		return (pointer);
	return (NULL);
}
