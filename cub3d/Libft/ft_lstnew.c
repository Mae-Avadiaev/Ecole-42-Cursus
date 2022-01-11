/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:30:30 by mclown            #+#    #+#             */
/*   Updated: 2020/11/12 16:31:04 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list1;

	list1 = (void *)malloc(sizeof(t_list));
	if (list1 == NULL)
		return (NULL);
	list1->next = NULL;
	list1->content = content;
	return (list1);
}
