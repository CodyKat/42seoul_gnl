/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:11:30 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/03/21 18:00:10 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	alloc_mem(char **save, char **read_line)
{
	if (*save == 0)
		*save = (char *)calloc(1, sizeof(char));
	*read_line = (char *)calloc(BUFFER_SIZE + 1, sizeof(char));
	if (*save == 0 || *read_line == 0 || *buffer == 0)
	{
		if (*save != 0)
			free(*save);
		if (*read_line != 0)
			free(*read_line);
		return (0);
	}
	return (1);
}

char	*return_line_save(char *save)
{
	char	*output_line;
	char	*tmp;
	int		index;

	output_line = (char *)calloc(1, sizeof(char));
	output_line = ft_strjoin(&output_line, save);
	tmp = save;
	index = 0;
	while (*tmp != '\n' && *tmp != '\0')
	{
		tmp++;
		index++;
	}
	if (*tmp == '\n')
		index++;

	ft_memmove(save, save + index, ft_strlen(save) - index + 1);
	return (output_line);
}

int	ft_is_in_new_line(char *line)
{
	while (1)
	{
		if (*line == '\0')
			return (0);
		else if (*line == '\n')
			return (1);
		line++;

	}
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*read_line;
	int			status;

	alloc_mem(&save, &read_line);
	if (*save == '\0')
	{
		while (1)
		{
			status = read(fd, read_line, BUFFER_SIZE);
			if (status == 0 && *save == '\0')
			{
				free(save);
				free(read_line);
				return (0);
			}
			save = ft_strjoin(&save, read_line);
			if (ft_is_in_new_line(read_line) || status != BUFFER_SIZE)
				return (return_line_save(save));
			ft_bzero(read_line, BUFFER_SIZE);
		}
	}
	else if (ft_is_in_new_line(save))
		return (return_line_save(save));
	while (1)
	{
		status = read(fd, read_line, BUFFER_SIZE);
		if (status == 0)
			return (return_line_save(save));
		save = ft_strjoin(&save, read_line);
		ft_bzero(read_line, BUFFER_SIZE);
	}
}
