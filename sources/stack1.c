/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:36:40 by mapryl            #+#    #+#             */
/*   Updated: 2020/03/13 17:32:29 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "utils.h"
#include <stdlib.h>

int		stack_create(s_stack *stack, int size)
{
	stack->stackVals = (int*)malloc(size * sizeof(int));
	if (!stack->stackVals)
		error("stack_create");
	stack->curPtr = -1;
	stack->size = size;
	return (1);
}

void	stack_delete(s_stack *stack)
{
	stack->size = 0;
	stack->curPtr = -1;
	free(stack->stackVals);
}

void	stack_copy(s_stack *dst_stack, const s_stack *src_stack)
{
	int		i;

	if (dst_stack->size != src_stack->size)
		error("stack_copy stacks of different size shall not be copied");
	dst_stack->curPtr = src_stack->curPtr;
	i = 0;
	while (i++ <= src_stack->curPtr)
		dst_stack->stackVals[i - 1] = src_stack->stackVals[i - 1];
}

void	stack_rotate_up(s_stack *stack)
{
	int		i;
	int		first;

	i = stack->curPtr;
	if (i < 1)
		return ;
	first = stack->stackVals[i];
	while (i)
	{
		stack->stackVals[i] = stack->stackVals[i - 1];
		--i;
	}
	stack->stackVals[0] = first;
}

void	stack_rotate_down(s_stack *stack)
{
	int		cur_size;
	int		last;
	int		i;

	cur_size = stack->curPtr;
	if (cur_size < 1)
		return ;
	last = stack->stackVals[0];
	i = 1;
	while (i <= cur_size)
	{
		stack->stackVals[i - 1] = stack->stackVals[i];
		++i;
	}
	stack->stackVals[stack->curPtr] = last;
}
