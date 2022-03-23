/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:25:45 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/03/21 21:27:29 by jaemjeon         ###   ########.fr       */
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

char	*update_save(char **save)
{
	char	*new_save;
	int		pull_len;
	int		oneline_len;

	pull_len = ft_strlen(*save, '\0');
	oneline_len = ft_strlen(*save, '\n');
	new_save = (char *)ft_calloc(sizeof(char), pull_len - oneline_len);
	ft_memcpy(new_save, *save + oneline_len + 1, pull_len - oneline_len);
	free(*save);
	return (new_save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	char		*buffer;
	int			status;

	line = (char *)ft_calloc(sizeof(char), 1);
	if (save == 0)
		save = (char *)calloc(sizeof(char), BUFFER_SIZE + 1);
	line = ft_alloced_strnjoin(&line, save, ft_strlen(save, '\n') + 1);
	save = update_save(&save);
	if (ft_strlen(save, '\0') != 0 && ft_strlen(line, '\0') != 0)
		return (line);
	buffer = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	while (1)
	{
		status = read(fd, buffer, BUFFER_SIZE);
		if (ft_strlen(line, '\0') == 0 && ft_strlen(buffer, '\0') == 0)
		{
			free(buffer);
			return (0);
		}
		if (status == -1)
		{
			free(buffer);
			free(line);
			return (0);
		}
		save = ft_alloced_strnjoin(&save, buffer, status);
		if ((ft_strlen(save, '\n') + 1 == ft_strlen(save, '\0') && BUFFER_SIZE != 1) || 
				(BUFFER_SIZE == 1 && ft_strlen(buffer, '\0') == 0))
		{
			line = ft_alloced_strnjoin(&line, save, ft_strlen(save, '\n') + 1);
			save = update_save(&save);
			break ;
		}
	}
	free(buffer);
	return (line);
}
