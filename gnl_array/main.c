#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
char	*get_next_line(int fd);

int main()
{
	int fd;

		char *string;
	while (1)
	{
		fd = open("./test", O_RDONLY);
		string = get_next_line(fd);
		if (string == 0)
			break;
		printf("%d", fd);
		free(string);
	}
	return 0;
}
