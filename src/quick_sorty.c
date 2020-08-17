/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sorty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:03:23 by amargy            #+#    #+#             */
/*   Updated: 2020/02/27 19:18:37 by amargy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		partition(int *ser, int low, int high)
{
	int i;
	int j;
	int pivot;

	pivot = ser[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (ser[j] < pivot)
		{
			i++;
			quick_sort_swap(&ser[i], &ser[j]);
		}
		j++;
	}
	quick_sort_swap(&ser[i + 1], &ser[high]);
	return (i + 1);
}

void	ft_quick_sort(int *ser, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(ser, low, high);
		ft_quick_sort(ser, low, pivot - 1);
		ft_quick_sort(ser, pivot + 1, high);
	}
}
