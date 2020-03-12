#include <stdlib.h>
#include <stdio.h>

#include "stack_sort.h"
#include "sort_utils.h"
#include "utils.h"
#include "parse.h"

int read_array(int** result, int argc, char* argv[])
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

void print_cmd(cmd_t cmd)
{

}

int* gen_array(int size)
{
	int* array;

	array = (int*)malloc(sizeof(int) * size);

	for (int i = 0; i < size; ++i) {
		array[i] = size - i;
	}

	for (int i = 0; i < size; ++i) {
		swap(array + rand() % size, array + rand() % size);
	}

	return array;
}

void print_array(int* array, int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", array[i]);
	printf("\n");
}

void print_operations(operation_list_t *ops)
{
	operation_node_t *node;
	static const char* cmds[] =
	{
		"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"
	};

	node = ops->op;
	while (1)
	{
		printf("%s", cmds[node->cmd]);
		node = node->next;
		if (!node)
			break;
		printf("\n");
	}
}

int test(int size)
{
	int cmd_count;
	int* array = gen_array(size);

	two_stacks_t stacks;
	two_stacks_create(&stacks, size);
	two_stacks_init(&stacks, array, size);

	stack_sort_algo(&stacks);
	int result = is_sorted(stacks.a.stackVals, stacks.a.size);
	if (result != ORDER_DESCEND && result != ORDER_NOT_DEFINED)
		error("Not sorted!");
	else
		printf("%d:%d - ok\n\n", size, stacks.op_list.size);

	cmd_count = stacks.op_list.size;

	free(array);
	two_stacks_delete(&stacks);

	return cmd_count;
}

int main_push_swap(int argc, char* argv[])
{
	vector_t *vec;

	vec = parse(argc, argv);

	if (has_duplicates(vec->vals, vec->size))
		error("error");

	two_stacks_t stacks;
	two_stacks_create(&stacks, vec->size);
	two_stacks_init(&stacks, vec->vals, vec->size);

	stack_sort_algo(&stacks);
	print_operations(&stacks.op_list);

	two_stacks_delete(&stacks);
	vector_delete(vec);
	free(vec);
}

int main_checker(int argc, char* argv[])
{
	vector_t *vec;

	vec = parse(argc, argv);

	if (has_duplicates(vec->vals, vec->size))
		error("error");

	two_stacks_t stacks;
	two_stacks_create(&stacks, vec->size);
	two_stacks_init(&stacks, vec->vals, vec->size);


	two_stacks_delete(&stacks);
	vector_delete(vec);
	free(vec);
}