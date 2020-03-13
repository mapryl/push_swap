#include "../includes/stack.h"
#include "../includes/utils.h"
#include <stdlib.h>

void stack_init(stack_t* stack, int size, int* vals)
{
	int i;

	i = 0;
	while (i < size)
	{
		stack->stackVals[i] = vals[size - i - 1];
		++i;
	}

	stack->curPtr = i - 1;
}

void stack_push(stack_t* stack, int val)
{
	if (stack->curPtr == stack->size - 1)
		error("stack overflow");

	stack->stackVals[++stack->curPtr] = val;
}

int stack_pop(stack_t* stack, int* val)
{
	if (stack->curPtr == -1)
		return 0;

	*val = stack->stackVals[stack->curPtr--];

	stack->stackVals[stack->curPtr + 1] = -1; // xxxx only for debug!!! 

	return 1;
}

int stack_peek(stack_t* stack)
{
	if (stack->curPtr == -1)
		error("stack_peek error: stack is empty");

	return stack->stackVals[stack->curPtr];
}

int stack_size(stack_t* stack)
{
	return stack->curPtr + 1;
}