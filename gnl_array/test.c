#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd1 = open("test", 0);
	int fd2 = open("test", 0);
	int fd3 = open("test", 0);
	char *s1 = get_next_line(fd1);
	char *s2 = get_next_line(fd2);
	char *s3 = get_next_line(fd3);
	while (s1)
	{
		free(s1);
		free(s2);
		free(s3);
		s1 = get_next_line(fd1);
		s2 = get_next_line(fd2);
		s3 = get_next_line(fd3);
//		printf("%s", str);
	}
}
