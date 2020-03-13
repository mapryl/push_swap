/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_split.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 18:04:22 by mapryl            #+#    #+#             */
/*   Updated: 2020/03/13 18:04:44 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_SPLIT_H
# define STACK_SPLIT_H

# include "two_stacks.h"

void	stack_split(t_two_stacks *two_stacks, int is_stack_a,
		int descending_order);
void	stack_partition(t_two_stacks *two_stacks);

#endif
