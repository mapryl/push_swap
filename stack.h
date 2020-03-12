#ifndef __STACK_H__
#define __STACK_H__

typedef struct
{
	int size;
	int* stackVals;
	int curPtr;
} stack_t;

int stack_create(stack_t* stack, int size);
void stack_delete(stack_t* stack);
void stack_copy(stack_t* dst_stack, const stack_t* src_stack);
void stack_rotate_up(stack_t* stack);
void stack_rotate_down(stack_t* stack);
void stack_init(stack_t* stack, int size, int* vals);
void stack_push(stack_t* stack, int val);
int stack_pop(stack_t* stack, int* val);
int stack_peek(stack_t* stack);
int stack_size(stack_t* stack);

#endif
