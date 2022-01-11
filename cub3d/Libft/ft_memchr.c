/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:32:29 by mclown            #+#    #+#             */
/*   Updated: 2020/11/11 21:34:38 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*arr1;
	size_t			i;
	unsigned char	c1;

	i = 0;
	arr1 = (unsigned char *)arr;
	c1 = (unsigned char)c;
	while (i < n)
	{
		if (arr1[i] == c1)
			return ((void *)arr + i);
		i++;
	}
	return (NULL);
}
