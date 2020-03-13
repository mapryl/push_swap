#ifndef __STACK_INSERTION_SORT_UTILS_H__
#define __STACK_INSERTION_SORT_UTILS_H__

#include "two_stacks.h"

typedef enum
{
	DIRECTION_UP,
	DIRECTION_DOWN,
} dir_t;

typedef struct
{
	int val;
	dir_t dir;
} distance_t;

distance_t distance_to(s_stack* stack, int val);
int distance_between(s_stack* stack, int val1, int val2);
int idx_before(int pos, int size);
int insert_elem_cost(two_stacks_t *two_stacks, int val);
int select_elem(two_stacks_t *two_stacks);
void rotate_to_elem(two_stacks_t* two_stacks, int is_stack_a, int val);
void insert_with_rotation(two_stacks_t *two_stacks, int val, int size);
void insert_elem(two_stacks_t *two_stacks, int val);

#endif