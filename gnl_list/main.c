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
		if (loop_fd == 100)
			return 0;
		//printf("%s\n", line);
		//free(line);
	}
	return (0);
}
