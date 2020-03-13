/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_insertion_sort_utils1.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:04:33 by mapryl            #+#    #+#             */
/*   Updated: 2020/03/13 17:06:00 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_insertion_sort_utils.h"
#include "utils.h"

t_distance	distance_to(t_stack *stack, int val)
{
	int			size;
	int			pos;
	t_distance	result;

	size = stack_size(stack);
	pos = size - find_in_array(stack->stack_vals, size, val) - 1;
	if (pos == -1)
		error("Error\n");
	result.dir = (pos > size / 2) ? DIRECTION_DOWN : DIRECTION_UP;
	result.val = (pos > size / 2) ? size - pos : pos;
	return (result);
}

int			distance_between(t_stack *stack, int val1, int val2)
{
	int		size;
	int		pos1;
	int		pos2;
	int		dist;

	size = stack_size(stack);
	pos1 = size - find_in_array(stack->stack_vals, size, val1) - 1;
	pos2 = size - find_in_array(stack->stack_vals, size, val2) - 1;
	if (pos1 == -1)
		error("Error\n");
	if (pos2 == -1)
		error("Error\n");
	dist = abs(pos1 - pos2);
	return ((dist > size / 2) ? size - dist : dist);
}

int			idx_before(int pos, int size)
{
	return ((pos > 0) ? pos - 1 : size - 1);
}

int			insert_elem_cost(t_two_stacks *two_stacks, int val)
{
	int		size;
	int		*arr;
	int		i;
	int		pos;

	size = stack_size(&two_stacks->b);
	arr = two_stacks->b.stack_vals;
	if (size < 2)
		return (size);
	pos = -1;
	i = 0;
	while (i++ < size)
	{
		if (
			(arr[idx_before(i - 1, size)] > arr[i - 1] &&
			(val > arr[idx_before(i - 1, size)] || val < arr[i - 1]))
			||
			(val > arr[idx_before(i - 1, size)] && val < arr[i - 1]))
		{
			pos = arr[idx_before(i - 1, size)];
			break ;
		}
	}
	return (distance_to(&two_stacks->b, pos).val);
}

int			select_elem(t_two_stacks *two_stacks)
{
	int		val;
	int		moves;
	int		cur_val;
	int		cur_moves;
	int		i;

	val = 0;
	moves = stack_size(&two_stacks->a) + stack_size(&two_stacks->b);
	i = 0;
	while (i++ < stack_size(&two_stacks->a))
	{
		cur_val = two_stacks->a.stack_vals[i - 1];
		cur_moves = distance_to(&two_stacks->a, cur_val).val +
			insert_elem_cost(two_stacks, cur_val);
		if (cur_moves < moves)
		{
			moves = cur_moves;
			val = cur_val;
		}
	}
	return (val);
}
