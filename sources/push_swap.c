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
#include "sort_utils.h"
#include "utils.h"
#include "parse.h"
#include "libft.h"

int		read_array(int **result, int argc, char **argv)
{
	int		*array;
	int		i;

	array = (int*)malloc(argc * sizeof(int));
	if (!array)
	{
		return (0);
	}
	*result = array;
	i = 0;
	while (i < argc)
	{
		array[i] = atoi(argv[i]);
		++i;
	}
	return (1);
}

void	print_array(int *array, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(array[i]);
		i++;
	}
	ft_putchar('\n');
}

void	print_operations(t_operation_list *ops)
{
	t_operation_node	*node;
	static const char	**cmds;

	cmds[0] = "sa";
	cmds[1] = "sb";
	cmds[2] = "ss";
	cmds[3] = "pa";
	cmds[4] = "pb";
	cmds[5] = "ra";
	cmds[6] = "rb";
	cmds[7] = "rr";
	cmds[8] = "rra";
	cmds[9] = "rrb";
	cmds[10] = "rrr";
	node = ops->op;
	while (1)
	{
		if (!node)
			break ;
		ft_putstr(cmds[node->cmd]);
		ft_putchar('\n');
		node = node->next;
	}
}

void	do_action(t_two_stacks *two_stacks, const char *cmd)
{
	two_stacks_command(two_stacks, get_cmd(cmd));
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
