/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflannel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 13:31:13 by mflannel          #+#    #+#             */
/*   Updated: 2020/03/15 17:45:35 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>

# define BUFF_SIZE 1000
# define FD_MAX 10240

int	get_next_line(const int fd, char **line);

#endif
