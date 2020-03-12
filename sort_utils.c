#include <stdlib.h>
#include "sort_utils.h"
#include "utils.h"

int is_sorted(int* array, int size)
{
	int sorted;
	int i;

	if (size < 2)
		return ORDER_NOT_DEFINED;

	i = 0;
	while (i + 1 < size && array[i] == array[i + 1])
		++i;

	if (i + 1 == size)
		return ORDER_NOT_DEFINED;

	sorted = (array[i] > array[i + 1]) ? ORDER_DESCEND : ORDER_ASCEND;

	while (i + 1 < size)
	{
		if (array[i] == array[i + 1] || my_sign(array[i + 1] - array[i]) == sorted)
			++i;
		else
			return ORDER_NOT;
	}

	return sorted;
}

void merge(int* array, int lo, int mid, int hi, int* aux)
{
	int i;
	int j;
	int k;

	i = lo;
	j = mid;
	k = 0;

	while (k < hi - lo)
	{
		if (i >= mid) aux[k++] = array[j++];
		else if (j >= hi) aux[k++] = array[i++];
		else if (array[i] < array[j]) aux[k++] = array[i++];
		else aux[k++] = array[j++];
	}

	k = 0;
	while (k < hi - lo)
	{
		array[k + lo] = aux[k];
		++k;
	}
}

void merge_sort_impl(int* array, int lo, int hi, int* aux)
{
	int mid;

	if (hi - lo < 2)
		return;

	mid = (hi + lo) / 2;
	merge_sort_impl(array, lo, mid, aux);
	merge_sort_impl(array, mid, hi, aux);

	merge(array, lo, mid, hi, aux);
}

void merge_sort(int* array, int size)
{
	int* arr;

	arr = (int*)malloc(sizeof(int) * size);
	if (!arr)
		exit(-1);

	merge_sort_impl(array, 0, size, arr);

	free(arr);
}

int middle_val(int* array, int size)
{
	int* arr;
	int middle_val;

	arr = clone_array(array, size);
	merge_sort(arr, size);

	middle_val = arr[size / 2];
	free(arr);

	return (middle_val);
}