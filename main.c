#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd);

int main()
{
	//int fd;

	//fd = open("./test", O_RDONLY);
	char *string = get_next_line(0);
	printf("%s", string);
	return 0;
}
