#ifndef __OPERATION_LIST_H__
#define __OPERATION_LIST_H__

#include "two_stacks_operation.h"

typedef struct operation_node
{
	cmd_t cmd;
	struct operation_node *next;
} operation_node_t;

typedef struct
{
	operation_node_t *op;
	int size;
} operation_list_t;

void operation_list_create(operation_list_t *op_list);
void operation_list_delete(operation_list_t *op_list);
void operation_list_add(operation_list_t *op_list, cmd_t cmd);
void operation_list_copy(operation_list_t *dst_list, const operation_list_t *src_list);

#endif