/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:21:31 by mapryl            #+#    #+#             */
/*   Updated: 2020/03/13 17:27:21 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "operation_list.h"
#include "utils.h"

void	operation_list_create(operation_list_t *op_list)
{
	op_list->op = NULL;
	op_list->size = 0;
}

void	operation_list_delete(operation_list_t *op_list)
{
	operation_node_t	*cur;
	operation_node_t	*next;

	cur = op_list->op;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	op_list->size = 0;
	op_list->op = NULL;
}

void	operation_list_add(operation_list_t *op_list, cmd_t cmd)
{
	operation_node_t	*new_node;
	operation_node_t	**cur;

	new_node = (operation_node_t*)malloc(sizeof(operation_node_t));
	if (!new_node)
		error("operation_list_add failed");
	new_node->next = NULL;
	new_node->cmd = cmd;
	cur = &op_list->op;
	while (*cur)
	{
		cur = &((*cur)->next);
	}
	*cur = new_node;
	++op_list->size;
}

void	operation_list_copy(operation_list_t *dst_list,
		const operation_list_t *src_list)
{
	operation_node_t	*cur;

	operation_list_delete(dst_list);
	cur = src_list->op;
	while (cur)
	{
		operation_list_add(dst_list, cur->cmd);
		cur = cur->next;
	}
}
