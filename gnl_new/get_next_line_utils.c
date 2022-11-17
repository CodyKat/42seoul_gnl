#include "get_next_line.h"
#include <unistd.h>

int	calcul_newline_count(char *string)
{
	int	ret;

	ret = 0;
	while (*string)
	{
		if (*string == '\n')
			ret++;
		string++;
	}
	return (ret);
}

int	strcat_newline(char *string1, char *string2)
{
	char		*dest;
	static int	cpy_count = 0;

	dest = string1;
	while (*dest)
		dest++;
	while (*(string2 + cpy_count) != '\0' && *(string2 + cpy_count) != '\n')
	{
		*dest++ = *(string2 + cpy_count);
		cpy_count++;
	}
	if (*string2 == '\n')
	{
		*dest++ = *(string2 + cpy_count);
		cpy_count++;
	}
	else
		cpy_count = 0;
	*dest = '\0';
	return (cpy_count);
}

int	readline(t_fd_port **port, int fd)
{
	t_word_block	*last_word_block;
	t_word_block	*new_block_pointer;
	ssize_t			l_ret;
	char			*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	l_ret = read(fd, buffer, BUFFER_SIZE);
	if (l_ret == 0 || l_ret == ERROR)
	{
		free(buffer);
		return (ERROR);
	}
	last_word_block = (*port)->head_block;
	while (last_word_block && last_word_block->next)
		last_word_block = last_word_block->next;
	if (last_word_block != NULL)
	{
		last_word_block->next = (t_word_block *)malloc(sizeof(t_word_block));
		new_block_pointer = last_word_block->next;
	}
	else
	{
		(*port)->head_block = (t_word_block *)malloc(sizeof(t_word_block));
		new_block_pointer = (*port)->head_block;
	}
	new_block_pointer->next = NULL;
	new_block_pointer->string = buffer;
	return (calcul_newline_count(new_block_pointer->string));
}

void	delete_head_word_block(t_fd_port *port)
{
	t_word_block	*to_delete_block;

	to_delete_block = port->head_block;
	port->head_block = to_delete_block->next;
	free(to_delete_block->string);
	free(to_delete_block);
}
