/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:31:10 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/03/19 22:23:09 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_new_line_eof(char *str)
{
	int	len;

	len = 0;
    if (*str == '\0')
        return (-1);
	while (*str != '\n' && *str != '\0')
	{
		len++;
		str++;
	}
    if (*str != '\n')
        return (0);
	return (len);
}

int read_buff(char **line, int fd, char *save)
{
    char    *buffer;
    int     status;

    buffer = (char*)calloc(sizeof(char), BUFFER_SIZE + 1);
    status = read(fd, buffer, BUFFER_SIZE);
    if (status == -1)
    {
        free(buffer);
        free(*line);
        return (-1);
    }
    *line = ft_strjoin(line, buffer);
    if (find_new_line_eof(buffer) != 0)
    {
        ft_bzero(save, BUFFER_SIZE);
        ft_memcpy(line, save, find_new_line_eof(buffer) + 1);
        free(buffer);
        return (BUFFER_SIZE + status + 1);
    }
    free(buffer);
    return (status);
}

char    *mapi_line(char *line)
{
    char    *new_line;
    int     len;

    len = 0;
    while (*line != '\0' && *line != '\n')
    {
        line++;
        len++;
    }
    new_line = (char*)malloc(sizeof(len + 1));
    ft_memcpy(new_line, line, len + 1);
    free(line);
    return (new_line);
}

char	*get_next_line(int fd)
{
    static char *save;
    char        *line;
    int         status;

    line = 0;
    if (save != 0)
    {
        line = (char *)calloc(sizeof(char), (int)ft_strlen(save) + 1);
        ft_memcpy(line, save, (int)ft_strlen(save) + 1);
    }
    while (1)
    {
        status = read_buff(&line, fd, save);
        if (status == -1)
        {
            if (save != 0)
                free(save);
            return (0);
        }
        else if (status > BUFFER_SIZE)
        {
            line = mapi_line(line);
            return (line);
        }
    }
}
