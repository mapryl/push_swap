/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:38:23 by mapryl            #+#    #+#             */
/*   Updated: 2020/03/13 17:23:13 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "utils.h"
#include <stdlib.h>

void	stack_init(s_stack *stack, int size, int *vals)
{
	int		i;

	i = 0;
	while (i < size)
	{
		stack->stackVals[i] = vals[size - i - 1];
		++i;
	}
	stack->curPtr = i - 1;
}

void	stack_push(s_stack *stack, int val)
{
	if (stack->curPtr == stack->size - 1)
		error("stack overflow");
	stack->stackVals[++stack->curPtr] = val;
}

int		stack_pop(s_stack *stack, int *val)
{
	if (stack->curPtr == -1)
		return (0);
	*val = stack->stackVals[stack->curPtr--];
	stack->stackVals[stack->curPtr + 1] = -1;
	return (1);
}

int		stack_peek(s_stack *stack)
{
	if (stack->curPtr == -1)
		error("stack_peek error: stack is empty");
	return (stack->stackVals[stack->curPtr]);
}

int		stack_size(s_stack *stack)
{
	return (stack->curPtr + 1);
}
