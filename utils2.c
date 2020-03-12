#include "utils.h"

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int find_in_array(int* arr, int size, int val)
{
	int i;

	i = 0;
	while (i < size)
		if (arr[i++] == val)
			return i - 1;

	return -1;
}

int abs(int i)
{
	return (i < 0) ? -i : i;
}

int find_max(int *arr, int size)
{
	int i;
	int max;

	max = arr[0];
	i = 1;
	while (i++ < size)
		if (arr[i - 1] > max)
			max = arr[i - 1];

	return max;
}

int str_len(const char *str)
{
	int result;

	result = 0;
	while (*str++)
		++result;

	return result;
}