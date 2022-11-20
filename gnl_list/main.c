#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>
#include<stdlib.h>

int	main()
{
	int	fd;
	char	*line;
	int loop_fd;

	fd = open("infile", O_RDONLY);
	loop_fd = 0;
	while (1)
	{
		line = get_next_line(loop_fd);
		loop_fd++;
		if (loop_fd == 3)
			break ;
			// return 0;
	}
	t_fd_port	*tmp_port;

	tmp_port = get_next_line(0);
	printf("first port add : %p\n", tmp_port);
	printf("second port add : %p\n", tmp_port->next);
	tmp_port = get_next_line(1);
	printf("second port add : %p", tmp_port);
	return (0);
}
