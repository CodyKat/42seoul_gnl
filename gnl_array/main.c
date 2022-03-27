#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
char	*get_next_line(int fd);

int main()
{
	int fd;

	char *string;
	fd = open("test1", O_RDONLY);
	while (1)
	{
		string = get_next_line(1);
		printf("%s", string);
		if (string != 0)
			free(string);
		printf("한바퀴\n");
	}
	return 0;
}
