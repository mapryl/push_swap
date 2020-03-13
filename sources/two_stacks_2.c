/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stacks_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:58:18 by mapryl            #+#    #+#             */
/*   Updated: 2020/03/13 17:05:22 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "two_stacks.h"
#include "utils.h"

void	two_stacks_command_sa(two_stacks_t *two_stacks)
{
	int		a1;
	int		a2;
	s_stack	*stack_a;

	stack_a = &two_stacks->a;
	if (stack_size(stack_a) < 2)
		return ;
	stack_pop(stack_a, &a1);
	stack_pop(stack_a, &a2);
	stack_push(stack_a, a1);
	stack_push(stack_a, a2);
}

void	two_stacks_command_sb(two_stacks_t *two_stacks)
{
	s_stack	*stack_b;
	int		b1;
	int		b2;

	stack_b = &two_stacks->b;
	if (stack_size(stack_b) < 2)
		return ;
	stack_pop(stack_b, &b1);
	stack_pop(stack_b, &b2);
	stack_push(stack_b, b1);
	stack_push(stack_b, b2);
}

void	two_stacks_command_ss(two_stacks_t *two_stacks)
{
	two_stacks_command_sa(two_stacks);
	two_stacks_command_sb(two_stacks);
}

void	two_stacks_command_pa(two_stacks_t *two_stacks)
{
	s_stack	*stack_b;
	s_stack	*stack_a;
	int		a;

	stack_b = &two_stacks->b;
	stack_a = &two_stacks->a;
	if (stack_pop(stack_b, &a))
		stack_push(stack_a, a);
}

void	two_stacks_command_pb(two_stacks_t *two_stacks)
{
	s_stack	*stack_b;
	s_stack	*stack_a;
	int		b;

	stack_b = &two_stacks->b;
	stack_a = &two_stacks->a;
	if (stack_pop(stack_a, &b))
		stack_push(stack_b, b);
}
