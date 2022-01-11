/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 22:05:00 by mclown            #+#    #+#             */
/*   Updated: 2020/11/11 22:07:54 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char		*p_dst;
	const char	*p_src;
	size_t		size_src;
	size_t		i;

	i = 0;
	p_dst = dst;
	p_src = src;
	if (!dst && !src)
		return (0);
	size_src = ft_strlen(src);
	while (p_src[i] != '\0' && i < size)
	{
		p_dst[i] = p_src[i];
		i++;
	}
	if (size != 0)
	{
		if (size <= size_src)
			p_dst[size - 1] = '\0';
		else
			p_dst[size_src] = '\0';
	}
	return (size_src);
}
