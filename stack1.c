#include "stack.h"
#include "utils.h"
#include <stdlib.h>

int stack_create(stack_t* stack, int size)
{
	stack->stackVals = (int*)malloc(size * sizeof(int));
	if (!stack->stackVals)
		error("stack_create");

	stack->curPtr = -1;
	stack->size = size;
	return 1;
}

void stack_delete(stack_t* stack)
{
	stack->size = 0;
	stack->curPtr = -1;
	free(stack->stackVals);
}

void stack_copy(stack_t* dst_stack, const stack_t* src_stack)
{
	int i;

	if (dst_stack->size != src_stack->size)
		error("stack_copy stacks of different size shall not be copied");

	dst_stack->curPtr = src_stack->curPtr;

	i = 0;
	while (i++ <= src_stack->curPtr)
		dst_stack->stackVals[i - 1] = src_stack->stackVals[i - 1];
}

void stack_rotate_up(stack_t* stack)
{
	int i;
	int first;

	i = stack->curPtr;
	if (i < 1)
		return;

	first = stack->stackVals[i];
	while (i)
	{
		stack->stackVals[i] = stack->stackVals[i - 1];
		--i;
	}

	stack->stackVals[0] = first;
}

void stack_rotate_down(stack_t* stack)
{
	int curSize;
	int last;
	int i;

	curSize = stack->curPtr;
	if (curSize < 1)
		return;

	last = stack->stackVals[0];
	i = 1;
	while (i <= curSize)
	{
		stack->stackVals[i - 1] = stack->stackVals[i];
		++i;
	}
	stack->stackVals[stack->curPtr] = last;
}