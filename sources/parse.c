/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:23:03 by mapryl            #+#    #+#             */
/*   Updated: 2020/03/13 17:28:46 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "vector.h"
#include "utils.h"
#include <stdlib.h>
#include "libft.h"

void		populate(const char *str, const char *delims, vector_t *vec)
{
	const char	*beg;

	beg = str;
	while (*str != 0)
		if (one_of(*str++, delims))
		{
			if (str - 1 == beg)
				;
			else
				vector_add(vec, as_int(beg, str - 1 - beg));
			beg = str;
		}
	if (beg != str)
		vector_add(vec, as_int(beg, str - beg));
}

vector_t	*parse_string(const char *str)
{
	vector_t *vec;

	vec = (vector_t*)malloc(sizeof(vector_t));
	if (!vec)
		error("parse_string");
	vector_create(vec);
	populate(str, " \t\n", vec);
	return (vec);
}

vector_t	*parse_many_strings(int argc, char **argv)
{
	int			i;
	vector_t	*vec;

	vec = (vector_t*)malloc(sizeof(vector_t));
	if (!vec)
		error("parse_string");
	vector_create(vec);
	i = 1;
	while (i < argc)
	{
		vector_add(vec, as_int(argv[i], ft_strlen(argv[i])));
		++i;
	}
	return (vec);
}

vector_t	*parse(int argc, char **argv)
{
	if (argc < 2)
	{
		error("");
		return (0);
	}
	else if (argc == 2)
		return (parse_string(argv[1]));
	else
		return (parse_many_strings(argc, argv));
}
