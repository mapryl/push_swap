/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stacks_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:54:55 by mapryl            #+#    #+#             */
/*   Updated: 2020/03/13 16:55:57 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "two_stacks.h"
#include "utils.h"

void	two_stacks_command_rrr(t_two_stacks *two_stacks)
{
	two_stacks_command_rra(two_stacks);
	two_stacks_command_rrb(two_stacks);
}

void	two_stacks_rest_command(t_two_stacks *two_stacks, t_cmd cmd)
{
	if (cmd == CMD_PB)
		two_stacks_command_pb(two_stacks);
	else if (cmd == CMD_RA)
		two_stacks_command_ra(two_stacks);
	else if (cmd == CMD_RB)
		two_stacks_command_rb(two_stacks);
	else if (cmd == CMD_RR)
		two_stacks_command_rr(two_stacks);
	else if (cmd == CMD_RRA)
		two_stacks_command_rra(two_stacks);
	else if (cmd == CMD_RRB)
		two_stacks_command_rrb(two_stacks);
	else if (cmd == CMD_RRR)
		two_stacks_command_rrr(two_stacks);
}

void	two_stacks_command(t_two_stacks *two_stacks, t_cmd cmd)
{
	if (cmd == CMD_SA)
		two_stacks_command_sa(two_stacks);
	else if (cmd == CMD_SB)
		two_stacks_command_sb(two_stacks);
	else if (cmd == CMD_SS)
		two_stacks_command_ss(two_stacks);
	else if (cmd == CMD_PA)
		two_stacks_command_pa(two_stacks);
	else
		two_stacks_rest_command(two_stacks, cmd);
	operation_list_add(&two_stacks->op_list, cmd);
}
