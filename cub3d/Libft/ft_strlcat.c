/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 22:09:53 by mclown            #+#    #+#             */
/*   Updated: 2020/11/11 22:12:13 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *restrict dst,
		const char *restrict src, size_t dstsize)
{
	size_t		len_dst;
	size_t		len_src;
	size_t		i;

	i = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	while (i < len_dst)
		i++;
	if (dstsize == 0)
		return (len_src + dstsize);
	while (i < len_dst + len_src && i < dstsize - 1)
	{
		dst[i] = src[i - len_dst];
		i++;
	}
	if ((len_dst) > dstsize)
		return (len_src + dstsize);
	else
		dst[i] = '\0';
	return (len_src + len_dst);
}
