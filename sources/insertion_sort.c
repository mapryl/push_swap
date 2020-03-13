/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:20:49 by mapryl            #+#    #+#             */
/*   Updated: 2020/03/13 17:26:59 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_insertion_sort.h"
#include "stack_insertion_sort_utils.h"
#include "utils.h"
#include "sort_utils.h"

void	stack_insertion_sort(two_stacks_t *two_stacks)
{
	s_stack		*stack_a;
	s_stack		*stack_b;
	int			cur_elem;

	stack_a = &two_stacks->a;
	stack_b = &two_stacks->b;
	while (stack_size(stack_a) > 0)
	{
		cur_elem = select_elem(two_stacks);
		rotate_to_elem(two_stacks, STACK_A, cur_elem);
		insert_elem(two_stacks, cur_elem);
	}
	rotate_to_elem(two_stacks, STACK_B, find_max(stack_b->stackVals,
				stack_size(stack_b)));
	while (stack_size(stack_b))
		two_stacks_command(two_stacks, CMD_PA);
}
