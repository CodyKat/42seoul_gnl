#include "get_next_line.h"
# include <stdlib.h>
// # include <fcntl.h>
# include <unistd.h>

t_word	*word_add_end(t_fd_port **port)
{
	t_word	*word_node;

	word_node = (*port)->head_word;
	if (word_node == NULL)
	{
		(*port)->head_word = (t_word *)malloc(sizeof(t_word));
		(*port)->rear_word = (*port)->head_word;
		(*port)->head_word->string = (char *)malloc(BUFFER_SIZE + 1);
		(*port)->head_word->start_idx = 0;
		(*port)->head_word->next = NULL;
		if ((*port)->head_word == NULL || (*port)->head_word->string == NULL)
			return (NULL);
		return ((*port)->head_word);
	}
	while (word_node->next)
		word_node = word_node->next;
	word_node->next = (t_word *)malloc(sizeof(t_word));
	word_node->next->string = (char *)malloc(BUFFER_SIZE + 1);
	word_node->next->start_idx = 0;
	word_node->next->next = NULL;
	(*port)->rear_word = word_node->next;
	if (word_node->next == NULL || word_node->next->string == NULL)
		return (NULL);
	return (word_node->next);
}

t_fd_port	*port_add_end(t_fd_port	**lst, int fd)
{
	t_fd_port	*tmp_port;

	if (*lst == NULL)
	{
		*lst = (t_fd_port *)malloc(sizeof(t_fd_port));
		(*lst)->next = NULL;
		(*lst)->fd = fd;
		(*lst)->head_word = NULL;
		(*lst)->rear_word = NULL;
		return (*lst);
	}
	tmp_port = *lst;
	while (tmp_port->next)
		tmp_port = tmp_port->next;
	tmp_port->next = (t_fd_port *)malloc(sizeof(t_fd_port));
	tmp_port->next->fd = fd;
	tmp_port->next->next = NULL;
	tmp_port->next->head_word = NULL;
	tmp_port->next->rear_word = NULL;
	return (tmp_port->next);
}

t_fd_port	*get_fd_port(int fd)
{
	static t_fd_port	*linked_fd_port;
	t_fd_port			*tmp_node;

	tmp_node = linked_fd_port;
	while (tmp_node->next)
	{
		if (tmp_node->fd == fd)
			return (tmp_node);
		tmp_node = tmp_node->next;
	}
	if (tmp_node->fd == fd)
		return (tmp_node);
	return (port_add_end(&linked_fd_port, fd));
}

int	get_newline_idx(t_word *word)
{
	char	*pstring;
	int		idx;

	idx = 0;
	pstring = &word->string[word->start_idx];
	while (pstring[idx] != '\0' || pstring[idx] != '\n')
		idx++;
	if (pstring[idx] == '\n')
		return (idx);
	return (-1);
}

char	*ft_memcpy(char *dst, size_t start_idx, char *src, size_t cpy_len)
{
	char	*to_put;
	size_t	i;

	if (dst == NULL || src == NULL)
		return (NULL);
	to_put = dst + start_idx;
	i = 0;
	while (i < cpy_len)
	{
		dst[start_idx + i] = src[i];
		i++;
	}
	return (dst);
}

char	*get_line(t_fd_port *port)
{
	char	*line;
	t_word	*word_node;
	t_word	*prev_node;
	int		line_len;
	int		i;

	line_len = 0;
	word_node = port->head_word;
	while (word_node && word_node->next)
	{
		line_len += BUFFER_SIZE;
		word_node = word_node->next;
	}
	line_len += get_newline_idx(word_node);
	line = (char *)malloc(sizeof(char) * (line_len + 1));
	if (line == NULL)
		return (NULL);
	word_node = port->head_word;
	i = 0;
	while (i < line_len / BUFFER_SIZE)
	{
		ft_memcpy(line, i * BUFFER_SIZE, word_node->string, BUFFER_SIZE);
		word_node = word_node->next;
		i++;
	}
	ft_memcpy(line, i * BUFFER_SIZE, word_node->string + word_node->start_idx, \
			get_newline_idx(word_node));
	word_node->start_idx += get_newline_idx(word_node);
	i = 0;
	word_node = port->head_word;
	while (i < line_len / BUFFER_SIZE)
	{
		free(word_node->string);
		prev_node = word_node;
		word_node = word_node->next;
		free(prev_node);
	}
	if (word_node->string[word_node->start_idx] == '\0')
	{
		free(word_node->string);
		free(word_node);
		port->head_word = NULL;
		port->rear_word = NULL;
	}
	else
		port->head_word = word_node;
	return (line);
}

char	*get_next_line(int fd)
{
	t_fd_port	*port;
	ssize_t		ret;
	char		*line;

	port = get_fd_port(fd);
	if (port == NULL)
		return (NULL);
	while (get_newline_idx(port->rear_word) == -1)
	{
		word_add_end(&port);
		ret = read(fd, port->rear_word->string, BUFFER_SIZE);
		if (ret == -1)
			return (NULL);
	}
	line = get_line(port);
	return (line);
}
