/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:09:04 by mclown            #+#    #+#             */
/*   Updated: 2020/10/29 20:46:53 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memccpy(void *restrict dst,
		const void *restrict src, int c, size_t n)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	size_t			i;

	i = 0;
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	while (i < n)
	{
		if (*src1 == (unsigned char)c)
		{
			*dst1 = *src1;
			return ((void *)dst + i + 1);
		}
		*dst1++ = *src1++;
		i++;
	}
	return (NULL);
}
