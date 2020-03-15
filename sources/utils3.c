/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:43:58 by mapryl            #+#    #+#             */
/*   Updated: 2020/03/15 16:52:25 by mapryl           ###   ########.fr       */
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

int		is_sign(char c, char c2)
{
	if ((c == '+' || c == '-') && c2 == '\0')
		error("Error\n");
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int		as_int(const char *term, int size)
{
	int		result;
	int		i;
	int		multiplier;
	int		temp;
	int		sign;

	i = size - 1;
	result = 0;
	sign = is_sign(term[0], term[1]);
	if (sign == 1)
		multiplier = (term[0] == '-' ? -1 : 1);
	else
		multiplier = 1;
	while (1)
	{
		temp = mply_secure(chtoi(term[i]), multiplier);
		result = sum_secure(result, temp);
		--i;
		if(i < sign)
			break;
		multiplier = mply_secure(multiplier, 10);
	}
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