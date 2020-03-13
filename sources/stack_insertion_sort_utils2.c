/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_insertion_sort_utils2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:13:08 by mapryl            #+#    #+#             */
/*   Updated: 2020/03/13 17:16:35 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_insertion_sort_utils.h"
#include "utils.h"
#include "sort_utils.h"

void	rotate_to_elem(two_stacks_t *two_stacks, int is_stack_a, int val)
{
	s_stack		*stack;
	distance_t	dist;
	int			i;
	cmd_t		cmd;

	stack = (is_stack_a) ? &two_stacks->a : &two_stacks->b;
	dist = distance_to(stack, val);
	i = dist.val;
	while (i-- > 0)
	{
		cmd = (dist.dir == DIRECTION_DOWN)
			? ((is_stack_a) ? CMD_RRA : CMD_RRB)
			: ((is_stack_a) ? CMD_RA : CMD_RB);
		two_stacks_command(two_stacks, cmd);
	}
}

void	insert_with_rotation(two_stacks_t *two_stacks, int val, int size)
{
	int		*arr;
	int		i;
	int		pos;

	arr = two_stacks->b.stackVals;
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
	rotate_to_elem(two_stacks, STACK_B, pos);
	two_stacks_command(two_stacks, CMD_PB);
}

void	insert_elem(two_stacks_t *two_stacks, int val)
{
	int		size;
	int		*arr;

	size = stack_size(&two_stacks->b);
	arr = two_stacks->b.stackVals;
	if (size == 0)
		two_stacks_command(two_stacks, CMD_PB);
	else if (size == 1)
	{
		two_stacks_command(two_stacks, CMD_PB);
		if (val < arr[0])
			two_stacks_command(two_stacks, CMD_SB);
	}
	else
		insert_with_rotation(two_stacks, val, size);
}
