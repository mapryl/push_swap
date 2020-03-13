#include <stdlib.h>
#include "../includes/two_stacks.h"
#include "../includes/utils.h"

void two_stacks_create(two_stacks_t* two_stacks, int size)
{
	stack_create(&two_stacks->a, size);
	stack_create(&two_stacks->b, size);
	operation_list_create(&two_stacks->op_list);
}

void two_stacks_init(two_stacks_t *two_stacks, int *vals, int size)
{
	stack_init(&two_stacks->a, size, vals);
}

void two_stacks_delete(two_stacks_t* two_stacks)
{
	stack_delete(&two_stacks->a);
	stack_delete(&two_stacks->b);
	operation_list_delete(&two_stacks->op_list);
}

void two_stacks_copy(two_stacks_t *dst_stacks, two_stacks_t *src_stacks)
{
	stack_copy(&dst_stacks->a, &src_stacks->a);
	stack_copy(&dst_stacks->b, &src_stacks->b);
	operation_list_copy(&dst_stacks->op_list, &src_stacks->op_list);
}