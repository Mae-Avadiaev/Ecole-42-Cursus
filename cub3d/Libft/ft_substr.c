/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:13:47 by mclown            #+#    #+#             */
/*   Updated: 2020/11/12 14:46:56 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;
	size_t	len_s;

	if (s == NULL)
		return ((char *)s);
	i = 0;
	len_s = ft_strlen(s);
	p = (char *)malloc(len * sizeof(char) + 1);
	if (len_s <= start)
	{
		p[0] = '\0';
		return (p);
	}
	if (p == NULL)
		return (NULL);
	while (s[start + i] != '\0' && i < len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
