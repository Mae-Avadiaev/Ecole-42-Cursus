/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 21:24:22 by mclown            #+#    #+#             */
/*   Updated: 2021/03/09 21:28:56 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		partition(t_pair *arr, int start, int stop)
{
	int		pivot;
	int		i;
	int		j;
	t_pair	bucket;

	pivot = start;
	i = start + 1;
	j = start + 1;
	while (j < stop + 1)
	{
		if (arr[j].dist <= arr[pivot].dist)
		{
			bucket = arr[j];
			arr[j] = arr[i];
			arr[i] = bucket;
			i++;
		}
		j++;
	}
	bucket = arr[pivot];
	arr[pivot] = arr[i - 1];
	arr[i - 1] = bucket;
	pivot = i - 1;
	return (pivot);
}

void	quick_sort(t_pair *arr, int start, int stop)
{
	int pivot_index;

	if (start < stop)
	{
		pivot_index = partition(arr, start, stop);
		quick_sort(arr, start, pivot_index - 1);
		quick_sort(arr, pivot_index + 1, stop);
	}
}

void	sort_sprites(t_sp_data *sp_data)
{
	int i;

	i = 0;
	if (sp_data->pair)
		free(sp_data->pair);
	sp_data->pair = malloc(sp_data->num_sp * sizeof(t_pair));
	while (i < sp_data->num_sp)
	{
		sp_data->pair[i].dist = sp_data->sp_dist[i];
		sp_data->pair[i].order = sp_data->sp_order[i];
		i++;
	}
	quick_sort(sp_data->pair, 0, sp_data->num_sp - 1);
	i = 0;
	while (i < sp_data->num_sp)
	{
		sp_data->sp_dist[i] = sp_data->pair[sp_data->num_sp - i - 1].dist;
		sp_data->sp_order[i] = sp_data->pair[sp_data->num_sp - i - 1].order;
		i++;
	}
}
