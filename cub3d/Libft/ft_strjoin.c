/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:03:12 by mclown            #+#    #+#             */
/*   Updated: 2020/11/12 15:03:19 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*p;
	size_t	len_s1_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	len_s1_s2 = ft_strlen(s1) + ft_strlen(s2);
	p = (char *)malloc((len_s1_s2) * sizeof(char) + 1);
	if (p == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		p[i++] = s2[j++];
	p[i] = '\0';
	return (p);
}
