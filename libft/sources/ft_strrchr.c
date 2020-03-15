/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <mapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:30:40 by mapryl            #+#    #+#             */
/*   Updated: 2020/03/15 17:50:49 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *last_pos;

	last_pos = 0;
	while (*s)
	{
		if (*s == c)
			last_pos = (char*)s;
		s++;
	}
	if (last_pos)
		return (last_pos);
	if (c == '\0')
		return ((char*)s);
	return (NULL);
}
