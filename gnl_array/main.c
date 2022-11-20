#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int main()
{
	char *line;
	int fd;

	fd = open("infile", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == 0)
			return (0);
		printf("%s", line);
		free(line);
	}
	return (0);
}