#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd);

int main()
{
	int fd;

	fd = open("./test", O_RDONLY);
	char *string;
	while (1)
	{
		string = get_next_line(fd);
		if (string == 0)
			break;
		printf("%s", string);
	}
	return 0;
}
