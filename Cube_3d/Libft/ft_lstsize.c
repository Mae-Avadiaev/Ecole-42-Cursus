/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:32:36 by mclown            #+#    #+#             */
/*   Updated: 2020/11/12 16:34:01 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*i;

	if (lst == NULL)
		return (0);
	len = 1;
	i = lst;
	while (i->next != NULL)
	{
		len++;
		i = i->next;
	}
	return (len);
}
