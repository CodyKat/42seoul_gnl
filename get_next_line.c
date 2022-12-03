#include "get_next_line_bonus.h"
# include <unistd.h>

t_fd_port	*add_new_port_end(t_fd_port **port, int fd)
{
	t_fd_port	*port_end;

	port_end = *port;
	if (port_end == NULL)
	{
		*port = (t_fd_port *)malloc(sizeof(t_fd_port));
		if (*port == NULL)
			return (NULL);
		(*port)->fd = fd;
		(*port)->head_word = NULL;
		(*port)->next = NULL;
		return (*port);
	}
	while (port_end->next)
		port_end = port_end->next;
	port_end->next = (t_fd_port *)malloc(sizeof(t_fd_port));
	if (port_end->next == NULL)
		return (NULL);
	port_end = port_end->next;
	port_end->fd = fd;
	port_end->head_word = NULL;
	port_end->next = NULL;
	return (port_end);
}

t_fd_port	*get_port(t_fd_port **port, int fd)
{
	t_fd_port	*ret_port;

	if (*port == NULL)
		ret_port = add_new_port_end(port, fd);
	else
	{
		ret_port = *port;
		while (ret_port->next && ret_port->fd != fd)
			ret_port = ret_port->next;
		if (ret_port->fd != fd)
			ret_port = add_new_port_end(port, fd);
	}
	return (ret_port);
}

t_word	*add_new_word_end(t_fd_port *port)
{
	t_word	*end_word;

	if (port->head_word == NULL)
	{
		port->head_word = (t_word *)malloc(sizeof(t_word));
		port->head_word->start_idx = 0;
		port->head_word->next = NULL;
		port->head_word->string = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		return (port->head_word);
	}
	end_word = port->head_word;
	while (end_word->next)
		end_word = end_word->next;
	end_word->next = (t_word *)malloc(sizeof(t_word));
	end_word->next->start_idx = 0;
	end_word->next->next = NULL;
	end_word->next->string = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	return (end_word->next);
}

int	has_newline(t_fd_port *port)
{
	t_word	*word_node;
	char	*pstring;

	word_node = port->head_word;
	if (word_node == NULL)
		return (FALSE);
	while (word_node->next)
		word_node = word_node->next;
	pstring = &word_node->string[word_node->start_idx];
	while (*pstring)
	{
		if (*pstring == '\n')
			return (TRUE);
		pstring++;
	}
	return (FALSE);
}

int	read_port(t_fd_port *port)
{
	t_word	*cur_word;
	ssize_t	ret;

	while (1)
	{
		cur_word = add_new_word_end(port);
		ret = read(port->fd, cur_word->string, BUFFER_SIZE);
		if (ret != BUFFER_SIZE)
			return (ret);
		if (has_newline(port))
			return (TRUE);
	}
}

t_line_info	get_line_info(t_fd_port *port)
{
	t_line_info	info;
	t_word		*word_node;

	word_node = port->head_word;
	if (word_node == NULL)
	{
		info.reserve_block_size = 0;
		info.len_tail = 0;
		return (info);
	}
	info.reserve_block_size = 0;
	while (word_node->next)
	{
		word_node = word_node->next;
		info.reserve_block_size++;
	}
	info.len_tail = 0;
	while (word_node->string[word_node->start_idx + info.len_tail] != '\0' && \
				word_node->string[word_node->start_idx + info.len_tail] != '\n')
		info.len_tail++;
	if (word_node->string[word_node->start_idx + info.len_tail] == '\n')
		info.len_tail++;
	return (info);
}

char	*get_one_line(char *line, t_fd_port *port, t_line_info *info)
{
	t_word		*word_node;
	t_word		*word_node_prev;
	int			i;

	word_node = port->head_word;
	i = -1;
	while (i++ < info->reserve_block_size)
	{
		word_node_prev = word_node;
		word_node = word_node->next;
		ft_strlcpy(line + BUFFER_SIZE * i, word_node_prev->string, \
						BUFFER_SIZE + 1);
		free(word_node_prev->string);
		free(word_node_prev);
	}
	port->head_word = word_node;
	if (word_node)
	{
		ft_strlcpy(line + BUFFER_SIZE * i, \
				word_node->string + word_node->start_idx, info->len_tail + 1);
		word_node->start_idx += info->len_tail;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_fd_port	*port = NULL;
	char				*line;
	t_line_info			line_info;
	t_fd_port			*cur_port;
	int					ret_status;

	cur_port = get_port(&port, fd);
	if (has_newline(cur_port) == FALSE)
	{
		ret_status = read_port(port);
		if (ret_status == ERROR)
			return (NULL);
	}
	line_info = get_line_info(cur_port);
	if (line_info.len_tail == 0 && line_info.reserve_block_size == 0)
	{
		free(cur_port->head_word->string);
		free(cur_port->head_word);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * \
		(line_info.reserve_block_size * BUFFER_SIZE + line_info.len_tail + 1));
	if (line == NULL)
		return (NULL);
	return (get_one_line(line, cur_port, &line_info));
}
