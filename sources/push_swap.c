#include <stdlib.h>

#include "stack_sort.h"
#include "sort_utils.h"
#include "utils.h"
#include "parse.h"
#include "libft.h"

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
		ft_putnbr(array[i]);
	ft_putchar('\n');
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
		if (!node)
			break;
		ft_putstr(cmds[node->cmd]);
		ft_putchar('\n');
		node = node->next;
	}
}

/*
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
*/

void do_action(two_stacks_t *two_stacks, const char *cmd)
{
	two_stacks_command(two_stacks, get_cmd(cmd));
}

int main(int argc, char* argv[])
{
	vector_t *vec;

	vec = parse(argc, argv);

	if (has_duplicates(vec->vals, vec->size))
		error("Error\n");

	two_stacks_t stacks;
	two_stacks_create(&stacks, vec->size);
	two_stacks_init(&stacks, vec->vals, vec->size);

	stack_sort_algo(&stacks);
	print_operations(&stacks.op_list);

	two_stacks_delete(&stacks);
	vector_delete(vec);
	free(vec);
}