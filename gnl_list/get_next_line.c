#include "get_next_line.h"
# include <stdlib.h>
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

#include <stdio.h>

char	*get_next_line(int fd)
{
	static t_fd_port	*port = NULL;
	t_fd_port			*cur_port;

	cur_port = get_port(&port, fd);

	// printf("port add : %p\n", cur_port);
	// printf("fd : %d\n", cur_port->fd);
	// printf("haed add : %p\n", cur_port->head_word);
	// printf("next : %p\n", cur_port->next);

	return (cur_port);
}
