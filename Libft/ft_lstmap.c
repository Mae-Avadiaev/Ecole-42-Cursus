/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:39:51 by mclown            #+#    #+#             */
/*   Updated: 2020/11/12 16:40:11 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*i;
	t_list	*j;
	t_list	*new;
	t_list	*res;

	(void)del;
	if (lst == NULL)
		return (lst);
	i = lst;
	res = ft_lstnew(f(i->content));
	j = res;
	while (i->next != NULL)
	{
		i = i->next;
		new = ft_lstnew(f(i->content));
		ft_lstadd_back(&j, new);
		j = j->next;
	}
	return (res);
}
