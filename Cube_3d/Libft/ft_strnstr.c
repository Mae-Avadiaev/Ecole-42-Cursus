/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 22:13:01 by mclown            #+#    #+#             */
/*   Updated: 2020/11/11 22:21:32 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	little_size;

	little_size = 0;
	while (needle[little_size] != '\0')
		little_size++;
	if (little_size == 0)
		return ((char *)haystack);
	while (len && haystack[0] != '\0' && little_size <= len)
	{
		if (haystack[0] == needle[0] &&
				ft_strncmp(haystack, needle, little_size) == 0)
			return ((char *)haystack);
		len--;
		haystack++;
	}
	return (NULL);
}
