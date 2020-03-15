/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:43:58 by mapryl            #+#    #+#             */
/*   Updated: 2020/03/13 16:48:17 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		chtoi(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (ch - 48);
	else
		error("Error\n");
	return (0);
}

int		as_int(const char *term, int size)
{
	int		result;
	int		i;
	int		multiplier;
	int		new_multiplier;
	int		sign;

	i = size - 1;
	result = 0;
	multiplier = 1;
	sign = 0;
	if (term[0] == '-' || term[0] == '+')
		sign = 1;
	while (i >= sign)
	{
		if (result > result + chtoi(term[i]) * multiplier)
			error("Error\n");
		result += chtoi(term[i]) * multiplier;
		new_multiplier = multiplier * 10;
		if (new_multiplier <= multiplier)
			error("Error\n");
		multiplier = new_multiplier;
		--i;
	}
	if (sign == 1)
		result *= (term[0] == '-' ? -1 : 1);
	return (result);
}

int		one_of(char ch, const char *str)
{
	while (*str++ && *(str - 1) != ch)
		;
	return (*(str - 1) == ch);
}

int		has_duplicates(int *arr, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j++])
				return (1);
		}
		++i;
	}
	return (0);
}
