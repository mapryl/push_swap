#include <stdlib.h>
#include "two_stacks.h"
#include "utils.h"

void two_stacks_command_sa(two_stacks_t* twoStacks)
{
	stack_t* stackA = &twoStacks->a;

	if (stack_size(stackA) < 2)
		return;

	int a1;
	int a2;
	stack_pop(stackA, &a1);
	stack_pop(stackA, &a2);
	stack_push(stackA, a1);
	stack_push(stackA, a2);
}

void two_stacks_command_sb(two_stacks_t* twoStacks)
{
	stack_t* stackB = &twoStacks->b;

	if (stack_size(stackB) < 2)
		return;

	int b1;
	int b2;
	stack_pop(stackB, &b1);
	stack_pop(stackB, &b2);
	stack_push(stackB, b1);
	stack_push(stackB, b2);
}

void two_stacks_command_ss(two_stacks_t* twoStacks)
{
	two_stacks_command_sa(twoStacks);
	two_stacks_command_sb(twoStacks);
}

void two_stacks_command_pa(two_stacks_t* twoStacks)
{
	stack_t* stackB;
	stack_t* stackA;
	int a;

	stackB = &twoStacks->b;
	stackA = &twoStacks->a;

	if (stack_pop(stackB, &a))
		stack_push(stackA, a);
}

void two_stacks_command_pb(two_stacks_t* twoStacks)
{
	stack_t* stackB;
	stack_t* stackA;
	int b;

	stackB = &twoStacks->b;
	stackA = &twoStacks->a;

	if (stack_pop(stackA, &b))
		stack_push(stackB, b);
}