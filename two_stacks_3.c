#include <stdlib.h>
#include "two_stacks.h"
#include "utils.h"

void two_stacks_command_ra(two_stacks_t* twoStacks)
{
	stack_rotate_up(&twoStacks->a);
}
void two_stacks_command_rb(two_stacks_t* twoStacks)
{
	stack_rotate_up(&twoStacks->b);
}
void two_stacks_command_rr(two_stacks_t* twoStacks)
{
	two_stacks_command_ra(twoStacks);
	two_stacks_command_rb(twoStacks);
}
void two_stacks_command_rra(two_stacks_t* twoStacks)
{
	stack_rotate_down(&twoStacks->a);
}
void two_stacks_command_rrb(two_stacks_t* twoStacks)
{
	stack_rotate_down(&twoStacks->b);
}
