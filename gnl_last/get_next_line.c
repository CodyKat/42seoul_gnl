#include "get_next_line.h"
#define FD_SIZE 5

char	*ft_calloc(size_t count, size_t size);
char	*ft_memcpy(void *dst, void *src, size_t n);

void	free_all(t_list **head)
{
	int	index;

	index = 0;
	while (index < FD_SIZE)
	{
		if (head[index]->text)
			free(head[index]->text);
		if (head[index])
			free(head[index]);
		index++;
	}
	if (head)
		free(head);
}

t_list	**init_list(t_list **head)
{
	t_list	**new_head;
	int		index;

	index = 0;
	if (head == 0)
	{
		new_head = (t_list **)ft_calloc(FD_SIZE, sizeof(t_list *));
		if (new_head == 0)
			return (0);
		while (index < FD_SIZE)
		{
			new_head[index] = (t_list *)ft_calloc(1, sizeof(t_list));
			new_head[index]->text = (char *)ft_calloc(1, sizeof(char));
			if (new_head[index] == 0 || new_head[index]->text == 0)
			{
				free_all(new_head);
				return (0);
			}
			new_head[index]->cursor = new_head[index]->text;
			new_head[index]->end = new_head[index]->text;
			index++;
		}
		return (new_head);
	}
	return (head);
}

char	*ft_update_buffer(t_list *node, int fd)
{
	char	*new_text;
	char	*buffer;
	int		status;

	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == 0)
		return (0);
	status = read(fd, buffer, BUFFER_SIZE);
	new_text = ft_strjoin(node, buffer);
	if (status == -1 || (node->cursor == node->end && status == 0))
	{
		free(buffer);
		free(new_text);
		return (0);
	}
	free(buffer);
	free(node->text);
	return (new_text);
}

char	*get_line(t_list *node, int fd)
{
	char	*line;
	int		line_len;

	line_len = ft_strlen(node->cursor, '\n');
	if (node->cursor != node->end)
	{
		line = (char *)ft_calloc(line_len + 1, sizeof(char));
		if (line == 0)
			return (0);
		ft_memcpy(line, node->cursor, line_len + 1);
		node->cursor += ft_strlen(node->cursor, '\n');//
		node->cursor += line_len;
		if (*(node->end - 1) == '\n')
			return (line);
	}
	while (1)
	{
		node->text = ft_update_buffer(node, fd);
		if (node->text == 0)
			return (0);
		if (ft_strlen(node->cursor, '\n') != node->end - node->cursor || *(node->end - 1) == '\n')
			return (get_line(node, fd));
	}
}

char	*get_next_line(int fd)
{
	static t_list	**head;
	char			*line;

	head = init_list(head);
	if (head == 0)
		return (0);
	line = get_line(head[fd], fd);
	if (line == 0)
	{
		free_all(head);
		return (0);
	}
	return (line);
}
