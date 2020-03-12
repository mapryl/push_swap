#include "utils.h"

int chtoi(char ch)
{
	if (ch >= 48 || ch <= 57)
		return ch - 48;
	else
		error("chtoi not a number");
	return 0;
}

int as_int(const char *term, int size)
{
	int result;
	int i;
	int multiplier;
	int new_multiplier;

	i = size - 1;
	result = 0;
	multiplier = 1;
	while (i >= 0)
	{
		if (result > result + chtoi(term[i]) * multiplier)
			error("as_int overflow");

		result += chtoi(term[i]) * multiplier;

		new_multiplier = multiplier * 10;
		if (new_multiplier <= multiplier)
			error("as_int  overflow");
		multiplier = new_multiplier;
		--i;
	}

	return result;
}

int one_of(char ch, const char *str)
{
	while (*str++ && *(str - 1) != ch);
	return *(str - 1) == ch;
}

int has_duplicates(int *arr, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j++])
				return 1;
		}
		++i;
	}

	return 0;
}