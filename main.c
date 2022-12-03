#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


int	main()
{
	int		fd;
	char	*line;

	fd = open("1MB.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
		// sleep(1);
	}
	// system("leaks a.out");
	// t_fd_port	*tmp_port;

	// tmp_port = get_next_line(0);
	// printf("first port add : %p\n", tmp_port);
	// printf("second port add : %p\n", tmp_port->next);
	// tmp_port = get_next_line(1);
	// printf("second port add : %p", tmp_port);
	return (0);
}
