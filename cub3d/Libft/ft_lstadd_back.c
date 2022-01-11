/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:35:44 by mclown            #+#    #+#             */
/*   Updated: 2020/11/12 16:36:27 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*i;

	if ((*lst) == NULL)
	{
		(*lst) = new;
		return ;
	}
	i = (*lst);
	while (i->next != NULL)
	{
		i = i->next;
	}
	i->next = new;
}
