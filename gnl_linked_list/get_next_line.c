#include "get_next_line.h"

static t_fd_port	*get_fd_port(t_fd_port *port, int fd)
{
	while (port)
	{
		if (port->fd == fd)
			return (port);
		port = port->next;
	}
	return (NULL);
}

static t_fd_port	*add_port(t_fd_port **port, int fd)
{
	t_fd_port	*cur_port;
	t_fd_port	*new_port_pointer;

	cur_port = *port;
	while (*port && (*port)->next)
		*port = (*port)->next;
	if (*port != NULL)
		*port = (*port)->next;
	*port = (t_fd_port *)malloc(sizeof(t_fd_port));
	if (*port == NULL)
		return (NULL);
	(*port)->fd = fd;
	(*port)->next = NULL;

	return (*port);
}

char	*get_next_line(int fd)
{
	static t_fd_port	*port = NULL;
	static int			newline_count = 0;
	t_fd_port			*cur_port;
	char				*result;

	cur_port = get_fd_port(port, fd);
	if (cur_port == NULL)
		cur_port = add_port(&port, fd);
	while (newline_count == 0)
	{
		newline_count += readline(&cur_port, fd);
		if (newline_count == ERROR)
			return (NULL);
	}
	result = malloc(sizeof(char) * (BUFFER_SIZE + 2));
	while (1)
	{
		if (strcat_newline(result, cur_port->head_block->string) == 0)
			delete_head_word_block(cur_port);
		else
			return (result);
	}
}
