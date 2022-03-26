#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
char	*get_next_line(int fd);

int main()
{
	int fd;

		char *string;
		//fd = open("test", O_RDONLY);
		string = get_next_line(2);
		printf("%s", string);
		free(string);
	return 0;
}
