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

int		stack_create(t_stack *stack, int size)
{
	stack->stack_vals = (int*)malloc(size * sizeof(int));
	if (!stack->stack_vals)
		error("Error\n");
	stack->cur_ptr = -1;
	stack->size = size;
	return (1);
}

void	stack_delete(t_stack *stack)
{
	stack->size = 0;
	stack->cur_ptr = -1;
	free(stack->stack_vals);
}

void	stack_copy(t_stack *dst_stack, const t_stack *src_stack)
{
	int		i;

	if (dst_stack->size != src_stack->size)
		error("Error\n");
	dst_stack->cur_ptr = src_stack->cur_ptr;
	i = 0;
	while (i++ <= src_stack->cur_ptr)
		dst_stack->stack_vals[i - 1] = src_stack->stack_vals[i - 1];
}

void	stack_rotate_up(t_stack *stack)
{
	int		i;
	int		first;

	i = stack->cur_ptr;
	if (i < 1)
		return ;
	first = stack->stack_vals[i];
	while (i)
	{
		stack->stack_vals[i] = stack->stack_vals[i - 1];
		--i;
	}
	stack->stack_vals[0] = first;
}

void	stack_rotate_down(t_stack *stack)
{
	int		cur_size;
	int		last;
	int		i;

	cur_size = stack->cur_ptr;
	if (cur_size < 1)
		return ;
	last = stack->stack_vals[0];
	i = 1;
	while (i <= cur_size)
	{
		stack->stack_vals[i - 1] = stack->stack_vals[i];
		++i;
	}
	stack->stack_vals[stack->cur_ptr] = last;
}
