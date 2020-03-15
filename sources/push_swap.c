/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:24:26 by mapryl            #+#    #+#             */
/*   Updated: 2020/03/13 17:31:13 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stack_sort.h"
#include "utils.h"
#include "parse.h"
#include "libft.h"

void	print_operations(t_operation_list *ops)
{
	t_operation_node	*node;
	static const char	*cmds[11];

	cmds[0] = "sa\n";
	cmds[1] = "sb\n";
	cmds[2] = "ss\n";
	cmds[3] = "pa\n";
	cmds[4] = "pb\n";
	cmds[5] = "ra\n";
	cmds[6] = "rb\n";
	cmds[7] = "rr\n";
	cmds[8] = "rra\n";
	cmds[9] = "rrb\n";
	cmds[10] = "rrr\n";
	node = ops->op;
	while (1)
	{
		if (!node)
			break ;
		ft_putstr(cmds[node->cmd]);
		node = node->next;
	}
}

int		main(int argc, char **argv)
{
	t_vector		*vec;
	t_two_stacks	stacks;

	vec = parse(argc, argv);
	if (has_duplicates(vec->vals, vec->size))
		error("Error\n");
	two_stacks_create(&stacks, vec->size);
	two_stacks_init(&stacks, vec->vals, vec->size);
	stack_sort_algo(&stacks);
	print_operations(&stacks.op_list);
	two_stacks_delete(&stacks);
	vector_delete(vec);
	free(vec);
}
