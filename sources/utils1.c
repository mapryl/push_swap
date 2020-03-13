/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:56:06 by mapryl            #+#    #+#             */
/*   Updated: 2020/03/13 16:57:19 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

void	error(const char *message)
{
	ft_putstr(message);
	exit(-1);
}

int		my_sign(int i)
{
	return ((i < 0) ? -1 : 1);
}

int		*clone_array(int *array, int size)
{
	int		*new_arr;
	int		i;

	new_arr = (int*)malloc(sizeof(int) * size);
	if (!new_arr)
		exit(-1);
	i = 0;
	while (i < size)
	{
		new_arr[i] = array[i];
		++i;
	}
	return (new_arr);
}

int		mymin(int a, int b)
{
	return (a < b ? a : b);
}

int		mymax(int a, int b)
{
	return (a > b ? a : b);
}