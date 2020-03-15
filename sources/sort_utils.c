/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:34:20 by mapryl            #+#    #+#             */
/*   Updated: 2020/03/13 17:21:43 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sort_utils.h"
#include "utils.h"

int		is_sorted(int *array, int size)
{
	int		sorted;
	int		i;

	if (size < 2)
		return (ORDER_NOT_DEFINED);
	i = 0;
	while (i + 1 < size && array[i] == array[i + 1])
		++i;
	if (i + 1 == size)
		return (ORDER_NOT_DEFINED);
	sorted = (array[i] > array[i + 1]) ? ORDER_DESCEND : ORDER_ASCEND;
	while (i + 1 < size)
	{
		if (array[i] == array[i + 1] ||
				my_sign(array[i + 1] - array[i]) == sorted)
			++i;
		else
			return (ORDER_NOT);
	}
	return (sorted);
}

void	merge(t_merge_sort_input *input)
{
	int		i;
	int		j;
	int		k;

	i = input->lo;
	j = input->mid;
	k = 0;
	while (k < input->hi - input->lo)
	{
		if (i >= input->mid)
			input->aux[k++] = input->array[j++];
		else if (j >= input->hi)
			input->aux[k++] = input->array[i++];
		else if (input->array[i] < input->array[j])
			input->aux[k++] = input->array[i++];
		else
			input->aux[k++] = input->array[j++];
	}
	k = 0;
	while (k < input->hi - input->lo)
	{
		input->array[k + input->lo] = input->aux[k];
		++k;
	}
}

void	merge_sort_impl(int *array, int lo, int hi, int *aux)
{
	int		mid;
	t_merge_sort_input merge_input;

	if (hi - lo < 2)
		return ;
	mid = (hi + lo) / 2;
	merge_sort_impl(array, lo, mid, aux);
	merge_sort_impl(array, mid, hi, aux);

	merge_input.array = array;
	merge_input.lo = lo;
	merge_input.mid = mid;
	merge_input.hi = hi;
	merge_input.aux = aux;
	merge(&merge_input);
}

void	merge_sort(int *array, int size)
{
	int		*arr;

	arr = (int*)malloc(sizeof(int) * size);
	if (!arr)
		exit(-1);
	merge_sort_impl(array, 0, size, arr);
	free(arr);
}

int		middle_val(int *array, int size)
{
	int		*arr;
	int		middle_val;

	arr = clone_array(array, size);
	merge_sort(arr, size);
	middle_val = arr[size / 2];
	free(arr);
	return (middle_val);
}
