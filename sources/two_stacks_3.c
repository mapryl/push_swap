/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stacks_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:49:15 by mapryl            #+#    #+#             */
/*   Updated: 2020/03/13 17:07:40 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "two_stacks.h"
#include "utils.h"

void	two_stacks_command_ra(two_stacks_t *two_stacks)
{
	stack_rotate_up(&two_stacks->a);
}

void	two_stacks_command_rb(two_stacks_t *two_stacks)
{
	stack_rotate_up(&two_stacks->b);
}

void	two_stacks_command_rr(two_stacks_t *two_stacks)
{
	two_stacks_command_ra(two_stacks);
	two_stacks_command_rb(two_stacks);
}

void	two_stacks_command_rra(two_stacks_t *two_stacks)
{
	stack_rotate_down(&two_stacks->a);
}

void	two_stacks_command_rrb(two_stacks_t *two_stacks)
{
	stack_rotate_down(&two_stacks->b);
}
