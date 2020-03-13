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

void	stack_init(t_stack *stack, int size, int *vals)
{
	int		i;

	i = 0;
	while (i < size)
	{
		stack->stack_vals[i] = vals[size - i - 1];
		++i;
	}
	stack->cur_ptr = i - 1;
}

void	stack_push(t_stack *stack, int val)
{
	if (stack->cur_ptr == stack->size - 1)
		error("Error\n");
	stack->stack_vals[++stack->cur_ptr] = val;
}

int		stack_pop(t_stack *stack, int *val)
{
	if (stack->cur_ptr == -1)
		return (0);
	*val = stack->stack_vals[stack->cur_ptr--];
	stack->stack_vals[stack->cur_ptr + 1] = -1;
	return (1);
}

int		stack_peek(t_stack *stack)
{
	if (stack->cur_ptr == -1)
		error("Error\n");
	return (stack->stack_vals[stack->cur_ptr]);
}

int		stack_size(t_stack *stack)
{
	return (stack->cur_ptr + 1);
}
