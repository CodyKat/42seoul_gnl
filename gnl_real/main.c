#include <fcntl.h>
#include <stdio.h>


char    *get_next_line(int fd);
int main()
{
    int fd;
    char    *line;

    fd = open("./test", O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (line == 0)
            break;
        printf("%s", line);
    }
    return (0);
}
