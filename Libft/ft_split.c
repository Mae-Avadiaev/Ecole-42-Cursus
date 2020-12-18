/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:24:07 by mclown            #+#    #+#             */
/*   Updated: 2020/11/17 18:21:41 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		**allocate(size_t count_words)
{
	char	**res;

	res = (char **)malloc((count_words + 1) * sizeof(char*));
	if (res == NULL)
		return (NULL);
	res[count_words] = NULL;
	return (res);
}

static size_t	f_count_words(char const *s, char c)
{
	size_t	count_words;

	count_words = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count_words++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count_words);
}

static size_t	count_syms(char const *s, char c)
{
	size_t	count_syms;

	count_syms = 0;
	while (*s && *s != c)
	{
		count_syms++;
		s++;
	}
	return (count_syms);
}

void			*free_memory(char **res, int i)
{
	while (i >= 0)
		free(res[i--]);
	free(res);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	char	**res;
	size_t	count_words;

	if (s == NULL)
		return (NULL);
	count_words = f_count_words(s, c);
	if ((res = allocate(count_words)) == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			if ((res[i] = ft_substr(s, 0, count_syms(s, c))) == NULL)
				return (free_memory(res, i));
		}
		s += count_syms(s, c);
		i++;
	}
	return (res);
}
