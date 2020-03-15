/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:56:21 by mapryl            #+#    #+#             */
/*   Updated: 2020/03/13 17:57:33 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "two_stacks_operation.h"

void	error(const char *message);
int		my_sign(int i);
int		*clone_array(int *array, int size);
void	swap(int *a, int *b);
int		find_in_array(int *arr, int size, int val);
int		abs(int i);
int		find_max(int *arr, int size);
int		chtoi(char ch);
int		as_int(const char *term, int size);
int		one_of(char ch, const char *str);
int		has_duplicates(int *arr, int size);
t_cmd	get_cmd(const char *cmd);
int		is_sign(char c, char c2);

#endif
