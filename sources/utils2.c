#include "utils.h"
#include "libft.h"

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

cmd_t get_cmd(const char *cmd)
{
	if(ft_strcmp("sa", cmd) == 0)
		return (CMD_SA);
	if(ft_strcmp("sb", cmd) == 0)
		return (CMD_SB);
	if(ft_strcmp("ss", cmd) == 0)
		return (CMD_SS);
	if(ft_strcmp("pa", cmd) == 0)
		return (CMD_PA);
	if(ft_strcmp("pb", cmd) == 0)
		return (CMD_PB);
	if(ft_strcmp("ra", cmd) == 0)
		return (CMD_RA);
	if(ft_strcmp("rb", cmd) == 0)
		return (CMD_RB);
	if(ft_strcmp("rr", cmd) == 0)
		return (CMD_RR);
	if(ft_strcmp("rra", cmd) == 0)
		return (CMD_RRA);
	if(ft_strcmp("rrb", cmd) == 0)
		return (CMD_RRB);
	if(ft_strcmp("rrr", cmd) == 0)
		return (CMD_RRR);
	error("Error\n");
	return (0);
}