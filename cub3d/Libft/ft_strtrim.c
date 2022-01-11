/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:05:40 by mclown            #+#    #+#             */
/*   Updated: 2020/11/12 15:06:30 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	len_s1;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 != '\0' && ft_strchr(set, *s1))
		s1++;
	len_s1 = ft_strlen(s1);
	while (len_s1 && ft_strchr(set, s1[len_s1 - 1]))
		len_s1--;
	res = ft_substr(s1, 0, len_s1);
	return (res);
}
