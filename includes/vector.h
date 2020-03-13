/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 18:02:14 by mapryl            #+#    #+#             */
/*   Updated: 2020/03/13 18:04:13 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct	s_vector
{
	int	*vals;
	int	size;
	int	capacity;
}				t_vector;

void			vector_create(t_vector *vec);
void			vector_delete(t_vector *vec);
void			vector_add(t_vector *vec, int val);
int				vector_pop(t_vector *vec);

#endif
