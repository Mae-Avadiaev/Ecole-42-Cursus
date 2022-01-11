/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:10:03 by mclown            #+#    #+#             */
/*   Updated: 2020/11/12 14:10:33 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	*p;

	p = (size_t *)malloc(count * size);
	if (p == NULL)
		return (NULL);
	ft_bzero((void *)p, count * size);
	return ((void *)p);
}
