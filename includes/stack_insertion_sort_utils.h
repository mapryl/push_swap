/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_insertion_sort_utils.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:47:43 by mapryl            #+#    #+#             */
/*   Updated: 2020/03/13 17:49:38 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_INSERTION_SORT_UTILS_H
# define STACK_INSERTION_SORT_UTILS_H

# include "two_stacks.h"

typedef enum
{
	DIRECTION_UP,
	DIRECTION_DOWN,
}	t_dir;

typedef struct
{
	int		val;
	t_dir	dir;
}			t_distance;

t_distance	distance_to(t_stack *stack, int val);
int			distance_between(t_stack *stack, int val1, int val2);
int			idx_before(int pos, int size);
int			insert_elem_cost(t_two_stacks *two_stacks, int val);
int			select_elem(t_two_stacks *two_stacks);
void		rotate_to_elem(t_two_stacks *two_stacks, int is_stack_a, int val);
void		insert_with_rotation(t_two_stacks *two_stacks, int val, int size);
void		insert_elem(t_two_stacks *two_stacks, int val);

#endif
