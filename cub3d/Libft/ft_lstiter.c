/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:38:25 by mclown            #+#    #+#             */
/*   Updated: 2020/11/12 16:39:17 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*i;

	if (lst == NULL)
		return ;
	i = lst;
	while (i->next != NULL)
	{
		f(i->content);
		i = i->next;
	}
	f(i->content);
}
