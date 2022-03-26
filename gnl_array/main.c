#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
char	*get_next_line(int fd);

int main()
{
	int fd;

		char *string;
		fd = open("test", O_RDONLY);
        while (1)
        {
		    string = get_next_line(1);
		    printf("%s", string);
		    free(string);
        }
	return 0;
}
