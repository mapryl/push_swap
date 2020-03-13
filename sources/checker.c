#include "vector.h"
#include "two_stacks.h"
#include <unistd.h>
#include <stdlib.h>
#include "parse.h"
#include "utils.h"
#include "libft.h"
#include "sort_utils.h"

int main(int argc, char* argv[])
{
	vector_t *vec;
	char *line;
	int sort_result;

	vec = parse(argc, argv);

	if (has_duplicates(vec->vals, vec->size))
		error("Error\n");

	two_stacks_t stacks;
	two_stacks_create(&stacks, vec->size);
	two_stacks_init(&stacks, vec->vals, vec->size);

	while( get_next_line(0, &line) )
	{
		two_stacks_command(&stacks, get_cmd(line));
		free(line);
	}

	sort_result = is_sorted(stacks.a.stackVals, stack_size(&stacks.a));
	if((sort_result == ORDER_DESCEND || sort_result == ORDER_NOT_DEFINED) && stack_size(&stacks.b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);

	two_stacks_delete(&stacks);
	vector_delete(vec);
	free(vec);
}