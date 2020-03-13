/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:11:03 by mapryl            #+#    #+#             */
/*   Updated: 2020/03/13 17:12:52 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_sort.h"
#include "stack_insertion_sort.h"
#include "stack_split.h"
#include "sort_utils.h"
#include "stack_sort3.h"

void	hybrid_algo(two_stacks_t *two_stacks)
{
	two_stacks_t clone;

	two_stacks_create(&clone, two_stacks->a.size);
	two_stacks_copy(&clone, two_stacks);
	stack_partition(&clone);
	stack_insertion_sort(&clone);
	stack_insertion_sort(two_stacks);
	if (clone.op_list.size < two_stacks->op_list.size)
		two_stacks_copy(two_stacks, &clone);
	two_stacks_delete(&clone);
}

void	stack_sort5(two_stacks_t *two_stacks)
{
	stack_split(two_stacks, 1, 1);
	if (stack_size(&two_stacks->a) == 3)
	{
		stack_sort3(two_stacks, two_stacks->a.stackVals,
				STACK_A, DESCENDING_ORDER);
		if (two_stacks->b.stackVals[0] > two_stacks->b.stackVals[1])
			two_stacks_command(two_stacks, CMD_SB);
	}
	else
	{
		stack_sort3(two_stacks, two_stacks->b.stackVals, STACK_B,
				ASCENDING_ORDER);
		if (two_stacks->a.stackVals[0] < two_stacks->a.stackVals[1])
			two_stacks_command(two_stacks, CMD_SA);
	}
	while (stack_size(&two_stacks->b))
		two_stacks_command(two_stacks, CMD_PA);
}

void	stack_sort_algo(two_stacks_t *two_stacks)
{
	s_stack	*stack_a;
	int		result;

	stack_a = &two_stacks->a;
	result = is_sorted(stack_a->stackVals, stack_size(stack_a));
	if (result == ORDER_DESCEND || result == ORDER_NOT_DEFINED)
		return ;
	if (stack_size(stack_a) == 2)
		two_stacks_command(two_stacks, CMD_SA);
	else if (stack_size(stack_a) == 3)
		stack_sort3(two_stacks, stack_a->stackVals, STACK_A, DESCENDING_ORDER);
	else if (stack_size(stack_a) == 5)
		stack_sort5(two_stacks);
	else
		hybrid_algo(two_stacks);
}
