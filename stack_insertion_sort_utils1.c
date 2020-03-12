#include "stack_insertion_sort_utils.h"
#include "utils.h"

distance_t distance_to(stack_t* stack, int val)
{
	int size;
	int pos;
	distance_t result;

	size = stack_size(stack);
	pos = size - find_in_array(stack->stackVals, size, val) - 1;

	if (pos == -1)
		error("distance_to value not found");

	result.dir = (pos > size / 2) ? DIRECTION_DOWN : DIRECTION_UP;
	result.val = (pos > size / 2) ? size - pos : pos;
	return result;
}

int distance_between(stack_t* stack, int val1, int val2)
{
	int size;
	int pos1;
	int pos2;
	int dist;

	size = stack_size(stack);
	pos1 = size - find_in_array(stack->stackVals, size, val1) - 1;
	pos2 = size - find_in_array(stack->stackVals, size, val2) - 1;

	if (pos1 == -1)
		error("distance_to value not found");
	if (pos2 == -1)
		error("distance_to value not found");

	dist = abs(pos1 - pos2);
	return (dist > size / 2) ? size - dist : dist;
}

int idx_before(int pos, int size)
{
	return (pos > 0) ? pos - 1 : size - 1;
}

int insert_elem_cost(two_stacks_t *two_stacks, int val)
{
	int size;
	int *arr;
	int i;
	int pos;

	size = stack_size(&two_stacks->b);
	arr = two_stacks->b.stackVals;
	if (size < 2)
		return size;
	pos = -1;
	i = 0;
	while (i++ < size)
	{
		if (
			(arr[idx_before(i - 1, size)] > arr[i - 1] &&
			(val > arr[idx_before(i - 1, size)] || val < arr[i - 1]))
			||
			(val > arr[idx_before(i - 1, size)] && val < arr[i - 1])
			)
		{
			pos = arr[idx_before(i - 1, size)];
			break;
		}
	}
	return distance_to(&two_stacks->b, pos).val;
}

int select_elem(two_stacks_t *two_stacks)
{
	int val;
	int moves;
	int cur_val;
	int cur_moves;
	int i;

	moves = stack_size(&two_stacks->a) + stack_size(&two_stacks->b);
	i = 0;
	while (i++ < stack_size(&two_stacks->a))
	{
		cur_val = two_stacks->a.stackVals[i - 1];
		cur_moves = distance_to(&two_stacks->a, cur_val).val + insert_elem_cost(two_stacks, cur_val);
		if (cur_moves < moves)
		{
			moves = cur_moves;
			val = cur_val;
		}
	}

	return val;
}