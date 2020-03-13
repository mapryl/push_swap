#ifndef __TWO_STACKS_H__
#define __TWO_STACKS_H__

#include "stack.h"
#include "operation_list.h"

typedef struct {
	stack_t a;
	stack_t b;
	operation_list_t op_list;
} two_stacks_t;

void two_stacks_create(two_stacks_t* two_stacks, int size);
void two_stacks_init(two_stacks_t *two_stacks, int *vals, int size);
void two_stacks_delete(two_stacks_t* two_stacks);
void two_stacks_copy(two_stacks_t *dst_stacks, two_stacks_t *src_stacks);
void two_stacks_command_sa(two_stacks_t* twoStacks);
void two_stacks_command_sb(two_stacks_t* twoStacks);
void two_stacks_command_ss(two_stacks_t* twoStacks);
void two_stacks_command_pa(two_stacks_t* twoStacks);
void two_stacks_command_pb(two_stacks_t* twoStacks);
void two_stacks_command_ra(two_stacks_t* twoStacks);
void two_stacks_command_rb(two_stacks_t* twoStacks);
void two_stacks_command_rr(two_stacks_t* twoStacks);
void two_stacks_command_rra(two_stacks_t* twoStacks);
void two_stacks_command_rrb(two_stacks_t* twoStacks);
void two_stacks_command_rrr(two_stacks_t* twoStacks);
void two_stacks_rest_command(two_stacks_t *two_stacks, cmd_t cmd);
void two_stacks_command(two_stacks_t* two_stacks, cmd_t cmd);

#endif
