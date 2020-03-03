#include <stdlib.h>
#include <stdio.h>

void error(char *message)
{
	printf("%s", message);
	exit(-1);
}

int read_array(int **result, int argc, char* argv[])
{
	int* array = (int*)malloc(argc * sizeof(int));
	if (!array)
	{
		return 0;
	}

	*result = array;

	int i = 0;
	while (i < argc)
	{
		array[i] = atoi(argv[i]);
		++i;
	}

	return 1;
}

typedef struct
{
	int size;
	int* stackVals;
	int curPtr;
} stack_t;

int stack_create(stack_t* stack, int size)
{
	stack->stackVals = malloc(size * sizeof(int));
	if (!stack->stackVals)
	{

	}

	stack->curPtr = -1;
	stack->size = size;
	return 1;
}

void stack_delete(stack_t *stack)
{
	stack->size = 0;
	stack->curPtr = -1;
	free(stack->stackVals);
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

int stack_peek(stack_t *stack)
{
	if (stack->curPtr == -1)
		error("stack_peek error: stack is empty");

	return stack->stackVals[stack->curPtr];
}

int stack_size(stack_t* stack)
{
	return stack->curPtr + 1;
}

typedef struct {
	stack_t a;
	stack_t b;
	int cmd_counter;
} two_stacks_t;

void two_stacks_create(two_stacks_t* twoStacks, int size, int* vals)
{
	stack_create(&twoStacks->a, size);
	stack_create(&twoStacks->b, size);
	stack_init(&twoStacks->a, size, vals);
	twoStacks->cmd_counter = 0;
}

void two_stacks_delete(two_stacks_t *two_stacks)
{
	stack_delete(&two_stacks->a);
	stack_delete(&two_stacks->b);
}

typedef enum { 
	CMD_NO_OP,
	CMD_SA, 
	CMD_SB, 
	CMD_SS, 
	CMD_PA, 
	CMD_PB, 
	CMD_RA, 
	CMD_RB, 
	CMD_RR, 
	CMD_RRA, 
	CMD_RRB, 
	CMD_RRR
} cmd_t;

void twoStacksCommandSa(two_stacks_t* twoStacks)
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

void twoStacksCommandSb(two_stacks_t* twoStacks)
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

void twoStacksCommandSs(two_stacks_t* twoStacks)
{
	twoStacksCommandSa(twoStacks);
	twoStacksCommandSb(twoStacks);
}

void twoStacksCommandPa(two_stacks_t* twoStacks)
{
	stack_t *stackB;
	stack_t *stackA;
	int a;

	stackB = &twoStacks->b;
	stackA = &twoStacks->a;
	
	if (stack_pop(stackB, &a))
		stack_push(stackA, a);
}

void twoStacksCommandPb(two_stacks_t* twoStacks)
{
	stack_t *stackB;
	stack_t *stackA;
	int b;

	stackB = &twoStacks->b;
	stackA = &twoStacks->a;

	if (stack_pop(stackA, &b))
		stack_push(stackB, b);
}
void twoStacksCommandRa(two_stacks_t* twoStacks)
{
	stack_rotate_up(&twoStacks->a);
}
void twoStacksCommandRb(two_stacks_t* twoStacks)
{
	stack_rotate_up(&twoStacks->b);
}
void twoStacksCommandRr(two_stacks_t* twoStacks)
{
	twoStacksCommandRa(twoStacks);
	twoStacksCommandRb(twoStacks);
}
void twoStacksCommandRra(two_stacks_t* twoStacks)
{
	stack_rotate_down(&twoStacks->a);
}
void twoStacksCommandRrb(two_stacks_t* twoStacks)
{
	stack_rotate_down(&twoStacks->b);
}
void twoStacksCommandRrr(two_stacks_t* twoStacks)
{
	twoStacksCommandRra(twoStacks);
	twoStacksCommandRrb(twoStacks);
}

void twoStacksCommand(two_stacks_t* twoStacks,enum Cmd cmd)
{
	if (cmd == CMD_SA)
		twoStacksCommandSa(twoStacks);
	else if (cmd == CMD_SB)
		twoStacksCommandSb(twoStacks);
	else if (cmd == CMD_SS)
		twoStacksCommandSs(twoStacks);
	else if (cmd == CMD_PA)
		twoStacksCommandPa(twoStacks);
	else if (cmd == CMD_PB)
		twoStacksCommandPb(twoStacks);
	else if (cmd == CMD_RA)
		twoStacksCommandRa(twoStacks);
	else if (cmd == CMD_RB)
		twoStacksCommandRb(twoStacks);
	else if (cmd == CMD_RR)
		twoStacksCommandRr(twoStacks);
	else if (cmd == CMD_RRA)
		twoStacksCommandRra(twoStacks);
	else if (cmd == CMD_RRB)
		twoStacksCommandRrb(twoStacks);
	else if (cmd == CMD_RRR)
		twoStacksCommandRrr(twoStacks);
}

int my_sign(int i)
{
	return ((i < 0) ? -1 : 1);
}

# define ORDER_NOT_DEFINED 100
# define ORDER_DESCEND (-1)
# define ORDER_ASCEND 1
# define ORDER_NOT 2
// возвращает -1 если отсортирован по убыванию, 0 - не отстортирован,
// +1 - если отсортирован по возрастанию, 100 - не возможно сказать
int is_sorted(int *array, int size)
{
	int sorted;
	int i;

	if (size < 2)
		return ORDER_NOT_DEFINED;

	i = 0;
	while ( i + 1 < size && array[i] == array[i + 1])
		++i;

	if (i + 1 == size)
		return ORDER_NOT_DEFINED;

	sorted = (array[i] > array[i + 1]) ? ORDER_DESCEND : ORDER_ASCEND;

	while (i + 1 < size)
	{
		if(array[i] == array[i + 1] || my_sign(array[i + 1] - array[i]) == sorted)
			++i;
		else
			return ORDER_NOT;
	}

	return sorted;
}

void merge(int *array, int lo, int mid, int hi, int *aux)
{
	int i;
	int j;
	int k;

	i = lo;
	j = mid;
	k = 0;

	while (k < hi - lo)
	{
		if (i >= mid) aux[k++] = array[j++];
		else if (j >= hi) aux[k++] = array[i++];
		else if (array[i] < array[j]) aux[k++] = array[i++];
		else aux[k++] = array[j++];
	}

	k = 0;
	while (k < hi - lo)
	{
		array[k + lo] = aux[k];
		++k;
	}
}

void merge_sort_impl(int *array, int lo, int hi, int *aux)
{
	int mid;

	if (hi - lo < 2)
		return;

	mid = (hi + lo) / 2;
	merge_sort_impl(array, lo, mid, aux);
	merge_sort_impl(array, mid, hi, aux);

	merge(array, lo, mid, hi, aux);
}

int *clone_array(int *array, int size)
{
	int *new_arr;
	int i;

	new_arr = (int*)malloc(sizeof(int) * size);
	if (!new_arr)
		exit(-1);

	i = 0;
	while (i < size)
	{
		new_arr[i] = array[i];
		++i;
	}

	return new_arr;
}

void merge_sort(int* array, int size)
{
	int *arr;

	arr = (int*)malloc(sizeof(int)*size);
	if (!arr)
		exit(-1);

	merge_sort_impl(array, 0, size, arr);

	free(arr);
}

int middle_val(int *array, int size)
{
	int *arr;
	int middle_val;

	arr = clone_array(array, size);
	merge_sort(arr, size);

	middle_val = arr[size / 2];
	free(arr);

	return (middle_val);
}

void print_cmd(cmd_t cmd)
{
	static const char* cmds[] =
	{
		"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"
	};

	printf("%s\n", cmds[cmd]);
}

void add_command(two_stacks_t *two_stacks, cmd_t cmd)
{
	//print_cmd(cmd);
	twoStacksCommand(two_stacks, cmd);
	++two_stacks->cmd_counter;
}

# define STACK_A 1
# define STACK_B 0
# define DESCENDING_ORDER 1
# define ASCENDING_ORDER 0

int get_case_number(int *arr)
{
	int a1;
	int a2;
	int a3;

	a1 = arr[2];
	a2 = arr[1];
	a3 = arr[0];

	if (a1 < a2 && a2 < a3)
		return 0;
	else if (a1 < a2 && a2 > a3 && a1 > a3)
		return 1;
	else if (a1 > a2 && a2 < a3 && a1 > a3)
		return 2;
	else if (a1 > a2 && a2 > a3)
		return 3;
	else if (a1 > a2 && a2 < a3 && a1 < a3)
		return 4;
	else if (a1 < a2 && a2 > a3 && a1 < a3)
		return 5;

	error("unexpected if path");
	return 0;
}

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int mymax(int a, int b)
{
	return a > b ? a : b;
}

void order(int *a, int *b, int *c)
{
	int tmpa = min( *a, min(*b, *c));
	int tmpc = max(*a, max(*b, *c));
	int tmpb = *a + *b + *c - tmpa - tmpc;

	*a = tmpa;
	*b = tmpb;
	*c = tmpc;
}

void stack_sort3(two_stacks_t *two_stacks, int *arr, int descending_order, int is_stack_a)
{
	cmd_t cmds[6][2][2];
	int case_numb;

	cmds[0][0][0] = CMD_NO_OP;
	cmds[0][0][1] = CMD_NO_OP;
	cmds[0][1][0] = (is_stack_a) ? CMD_SA : CMD_SB;
	cmds[0][1][1] = (is_stack_a) ? CMD_RRA : CMD_RRB;
	cmds[1][0][0] = (is_stack_a) ? CMD_RRA : CMD_RRB;
	cmds[1][0][1] = CMD_NO_OP;
	cmds[1][1][0] = (is_stack_a) ? CMD_SA : CMD_SB;
	cmds[1][1][1] = CMD_NO_OP;
	cmds[2][0][0] = (is_stack_a) ? CMD_RA : CMD_RB;
	cmds[2][0][1] = CMD_NO_OP;
	cmds[2][1][0] = (is_stack_a) ? CMD_RRA : CMD_RRB;
	cmds[2][1][1] = (is_stack_a) ? CMD_SA : CMD_SB;
	cmds[3][0][0] = (is_stack_a) ? CMD_SA : CMD_SB;
	cmds[3][0][1] = (is_stack_a) ? CMD_RRA : CMD_RRB;
	cmds[3][1][0] = CMD_NO_OP;
	cmds[3][1][1] = CMD_NO_OP;
	cmds[4][0][0] = (is_stack_a) ? CMD_SA : CMD_SB;
	cmds[4][0][1] = CMD_NO_OP;
	cmds[4][1][0] = (is_stack_a) ? CMD_RRA : CMD_RRB;
	cmds[4][1][1] = CMD_NO_OP;
	cmds[5][0][0] = (is_stack_a) ? CMD_RRA : CMD_RRB;
	cmds[5][0][1] = (is_stack_a) ? CMD_SA : CMD_SB;
	cmds[5][1][0] = (is_stack_a) ? CMD_RA : CMD_RB;
	cmds[5][1][1] = CMD_NO_OP;

	case_numb = get_case_number(arr);
	//add_command(two_stacks, cmds[case_numb][!descending_order][0]);
	//add_command(two_stacks, cmds[case_numb][!descending_order][1]);

	two_stacks->cmd_counter += 2;
	descending_order ? order(&arr[2], &arr[1], &arr[0]) : order(&arr[0], &arr[1], &arr[2]);
}

void stack_sort(two_stacks_t *two_stacks, int size, int is_stack_a, int descending_order)
{
	stack_t *stack;
	int *arr;
	int middle;
	int i;
	int count;
	int result;

	stack = (is_stack_a) ? &two_stacks->a : &two_stacks->b;
	arr = stack->stackVals + stack_size(stack) - size;

	result = is_sorted(arr, size);
	if (result == ((descending_order) ? ORDER_DESCEND : ORDER_ASCEND) || result == ORDER_NOT_DEFINED)
	{
		i = 0;
		while ( !is_stack_a && i++ < size)
			add_command(two_stacks, CMD_PA);
		return;
	}

	if (size == 2)
	{
		add_command(two_stacks, (is_stack_a) ? CMD_SA : CMD_SB);
		if (!is_stack_a) { add_command(two_stacks, CMD_PA); add_command(two_stacks, CMD_PA);}
		return;
	}

	int under_stack_size = arr - stack->stackVals;
	if (size == 3)
	{
		//stack_sort3(two_stacks, arr, descending_order, is_stack_a);
		//return;
	}

	middle = middle_val(arr, size);
	i = 0;
	count = 0;

	int sizeB = stack_size(&two_stacks->b);

	while (i++ < size)
		if ( (descending_order && stack_peek(stack) <= middle) || (!descending_order && stack_peek(stack) > middle))
		{
			add_command(two_stacks, (is_stack_a) ? CMD_PB : CMD_PA);
			++count;
		}
		else
			add_command(two_stacks, (is_stack_a) ? CMD_RA : CMD_RB);

	i = 0;
	
	while(under_stack_size && i++ < ((size - count) % under_stack_size) )
		add_command(two_stacks, (is_stack_a) ? CMD_RRA : CMD_RRB);

	stack_sort(two_stacks, size - count, (is_stack_a) ? STACK_A : STACK_B, descending_order);
	stack_sort(two_stacks, count, (is_stack_a) ? STACK_B : STACK_A, !descending_order);
	  
	//i = 0;
	//while (i++ < count)
	//	add_command(two_stacks, (is_stack_a) ? CMD_PA : CMD_PB);

	//int remains = stack_size(&two_stacks->b) - sizeB;
	//while (i++ < remains)
	//	add_command(two_stacks, CMD_PA);
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int *gen_array(int size)
{
	int *array;

	array = (int*)malloc(sizeof(int) * size);

	for (int i = 0; i < size; ++i) {
		array[i] = i + 1;
	}

	for (int i = 0; i < size; ++i) {
		swap(array + rand() % size, array + rand() % size);
	}

	return array;
}

void print_array(int *array, int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", array[i]);
	printf("\n");
}

void test(int size)
{
	int *array = gen_array(size);
	print_array(array, size);

	two_stacks_t stacks;
	two_stacks_create(&stacks, size, array);

	stack_sort(&stacks, stacks.a.size, STACK_A, DESCENDING_ORDER);
	int result = is_sorted(stacks.a.stackVals, stacks.a.size);
	if (result != ORDER_DESCEND && result != ORDER_NOT_DEFINED)
		error("Not sorted!");
	else
		printf("%d:%d - ok\n\n", size, stacks.cmd_counter);

	free(array);
	two_stacks_delete(&stacks);
}

int main(int argc, char* argv[])
{
	//int *array = NULL;
	//if (!read_array(&array, argc, argv))
	//	exit(1);

	for (int i = 1; i < 2; ++i)
		test(20);
}

