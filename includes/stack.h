#ifndef __STACK_H__
#define __STACK_H__

typedef struct
{
	int size;
	int* stackVals;
	int curPtr;
} s_stack;

int stack_create(s_stack* stack, int size);
void stack_delete(s_stack* stack);
void stack_copy(s_stack* dst_stack, const s_stack* src_stack);
void stack_rotate_up(s_stack* stack);
void stack_rotate_down(s_stack* stack);
void stack_init(s_stack* stack, int size, int* vals);
void stack_push(s_stack* stack, int val);
int stack_pop(s_stack* stack, int* val);
int stack_peek(s_stack* stack);
int stack_size(s_stack* stack);

#endif
