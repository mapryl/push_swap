/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:50:16 by mapryl            #+#    #+#             */
/*   Updated: 2020/03/13 16:51:53 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>
#include "utils.h"

void	vector_create(t_vector *vec)
{
	vec->size = 0;
	vec->capacity = 5;
	vec->vals = (int*)malloc(sizeof(int) * vec->capacity);
	if (!vec->vals)
		error("vector_create");
}

void	vector_delete(t_vector *vec)
{
	vec->size = 0;
	vec->capacity = 0;
	free(vec->vals);
	vec->vals = NULL;
}

void	vector_add(t_vector *vec, int val)
{
	int		*new_arr;
	int		i;

	if (++vec->size <= vec->capacity)
		vec->vals[vec->size - 1] = val;
	else
	{
		vec->capacity *= 2;
		new_arr = (int*)malloc(sizeof(int) * vec->capacity);
		if (!new_arr)
			error("vector_add");
		i = 0;
		while (i++ < vec->size - 1)
			new_arr[i - 1] = vec->vals[i - 1];
		new_arr[vec->size - 1] = val;
		free(vec->vals);
		vec->vals = new_arr;
	}
}

int		vector_pop(t_vector *vec)
{
	if (vec->size > 0)
		--vec->size;
	return (vec->vals[vec->size + 1]);
}
