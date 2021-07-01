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
	void	*con1;
	t_list	*list1;

	list1 = (void *)malloc(sizeof(*content));
	if (list1 == NULL)
		return (NULL);
	con1 = content;
	*list1 = (t_list) { .content = con1, .next = NULL};
	return (list1);
}
