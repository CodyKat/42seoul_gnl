/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:31:10 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/03/20 22:19:38 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_new_line_eof(char *str)
{
	int	index;

	index = 0;
	while (index < BUFFER_SIZE && str[index] != 0 && str[index] != '\n')
		index++;
	if (str[index] == '\n')
		index++;
	return (index);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	char		*buffer;
	int			status;

	buffer = (char *)calloc(sizeof(char), BUFFER_SIZE + 1);
	line = (char *)calloc(sizeof(char), 1);
	if (save == 0)
		save = (char *)calloc(sizeof(char), BUFFER_SIZE + 1);
	line = ft_alloced_strnjoin(&line, save, ft_strlen(save));
	ft_bzero(save, BUFFER_SIZE);
	if (buffer == 0)
		return (0);
	while (1)
	{
		status = read(fd, buffer, BUFFER_SIZE);
		if (status == -1)
		{
			free(buffer);
			free(line);
			return (0);
		}
		status = find_new_line_eof(buffer);
		line = ft_alloced_strnjoin(&line, buffer, status);
		if (line == 0)
		{
			free(buffer);
			return (0);
		}
		if (status != BUFFER_SIZE || buffer[status] == '\n')
			break;
		ft_bzero(buffer, BUFFER_SIZE);
	}
	if (status < BUFFER_SIZE || buffer[status] == '\n')
		ft_memcpy(save, buffer + status, BUFFER_SIZE - status - 1);
	free(buffer);
	if (*line == 0)
	{
		free(line);
		return (0);
	}
	return (line);
}
