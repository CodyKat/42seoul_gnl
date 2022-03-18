/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:31:10 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/03/18 19:56:26 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE = 5

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	int			status;

	buffer = (char *)calloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == 0)
		return (0);
	status = read(fd, buffer, BUFFER_SIZE);
	if (status == -1)
		return (0);
	while (1)
	{
		line = ft_strjoin(line, buffer);
		if (line == 0)
			return (0);
		if (status != BUFFER_SIZE)
			break;
	}
	free(buffer);
	printf("%s", line);
	free(line);
	return (0);
}
