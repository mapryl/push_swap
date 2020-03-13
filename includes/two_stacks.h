/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stacks.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:51:11 by mapryl            #+#    #+#             */
/*   Updated: 2020/03/13 18:06:31 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWO_STACKS_H
# define TWO_STACKS_H

# include "stack.h"
# include "operation_list.h"

typedef struct			s_two_stacks
{
	t_stack				a;
	t_stack				b;
	t_operation_list	op_list;
}						t_two_stacks;

void					two_stacks_create(t_two_stacks *two_stacks, int size);
void					two_stacks_init(t_two_stacks *two_stacks, int *vals,
		int size);
void					two_stacks_delete(t_two_stacks *two_stacks);
void					two_stacks_copy(t_two_stacks *dst_stacks,
		t_two_stacks *src_stacks);
void					two_stacks_command_sa(t_two_stacks *two_stacks);
void					two_stacks_command_sb(t_two_stacks *two_stacks);
void					two_stacks_command_ss(t_two_stacks *two_stacks);
void					two_stacks_command_pa(t_two_stacks *two_stacks);
void					two_stacks_command_pb(t_two_stacks *two_stacks);
void					two_stacks_command_ra(t_two_stacks *two_stacks);
void					two_stacks_command_rb(t_two_stacks *two_stacks);
void					two_stacks_command_rr(t_two_stacks *two_stacks);
void					two_stacks_command_rra(t_two_stacks *two_stacks);
void					two_stacks_command_rrb(t_two_stacks *two_stacks);
void					two_stacks_command_rrr(t_two_stacks *two_stacks);
void					two_stacks_rest_command(t_two_stacks *two_stacks,
												t_cmd cmd);
void					two_stacks_command(t_two_stacks *two_stacks,
		t_cmd cmd);

#endif
