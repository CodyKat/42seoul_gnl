#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int fd;

	char *string;
	fd = open("test", O_RDONLY);
	while (1)
	{
		string = get_next_line(fd);
		printf("%s", string);
		if (string != 0)
			free(string);
		printf("한바퀴\n");
	}
	return 0;
}
