/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:52:07 by mapryl            #+#    #+#             */
/*   Updated: 2020/03/13 16:54:44 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_sort3.h"
#include "utils.h"

int		get_case_number(int *arr)
{
	int		a1;
	int		a2;
	int		a3;

	a1 = arr[2];
	a2 = arr[1];
	a3 = arr[0];
	if (a1 < a2 && a2 < a3)
		return (0);
	else if (a1 < a2 && a2 > a3 && a1 > a3)
		return (1);
	else if (a1 > a2 && a2 < a3 && a1 > a3)
		return (2);
	else if (a1 > a2 && a2 > a3)
		return (3);
	else if (a1 > a2 && a2 < a3 && a1 < a3)
		return (4);
	else if (a1 < a2 && a2 > a3 && a1 < a3)
		return (5);
	error("unexpected if path");
	return (0);
}

void	init_cmds_1(cmd_t cmds[][2][2], int is_stack_a)
{
	cmds[0][0][0] = CMD_NO_OP;
	cmds[0][0][1] = CMD_NO_OP;
	cmds[0][1][0] = (is_stack_a) ? CMD_SA : CMD_SB;
	cmds[0][1][1] = (is_stack_a) ? CMD_RRA : CMD_RRB;
	cmds[1][0][0] = (is_stack_a) ? CMD_RRA : CMD_RRB;
	cmds[1][0][1] = CMD_NO_OP;
	cmds[1][1][0] = (is_stack_a) ? CMD_SA : CMD_SB;
	cmds[1][1][1] = CMD_NO_OP;
	cmds[2][0][0] = (is_stack_a) ? CMD_RA : CMD_RB;
	cmds[2][0][1] = CMD_NO_OP;
	cmds[2][1][0] = (is_stack_a) ? CMD_RRA : CMD_RRB;
	cmds[2][1][1] = (is_stack_a) ? CMD_SA : CMD_SB;
	cmds[3][0][0] = (is_stack_a) ? CMD_SA : CMD_SB;
	cmds[3][0][1] = (is_stack_a) ? CMD_RRA : CMD_RRB;
	cmds[3][1][0] = CMD_NO_OP;
	cmds[3][1][1] = CMD_NO_OP;
}

void	init_cmds_2(cmd_t cmds[][2][2], int is_stack_a)
{
	cmds[4][0][0] = (is_stack_a) ? CMD_SA : CMD_SB;
	cmds[4][0][1] = CMD_NO_OP;
	cmds[4][1][0] = (is_stack_a) ? CMD_RRA : CMD_RRB;
	cmds[4][1][1] = CMD_NO_OP;
	cmds[5][0][0] = (is_stack_a) ? CMD_RRA : CMD_RRB;
	cmds[5][0][1] = (is_stack_a) ? CMD_SA : CMD_SB;
	cmds[5][1][0] = (is_stack_a) ? CMD_RA : CMD_RB;
	cmds[5][1][1] = CMD_NO_OP;
}

void	stack_sort3(two_stacks_t *two_stacks, int *arr, int descending_order,
		int is_stack_a)
{
	cmd_t	cmds[6][2][2];
	int		case_numb;

	init_cmds_1(cmds, is_stack_a);
	init_cmds_2(cmds, is_stack_a);
	case_numb = get_case_number(arr);
	two_stacks_command(two_stacks, cmds[case_numb][!descending_order][0]);
	two_stacks_command(two_stacks, cmds[case_numb][!descending_order][1]);
}
