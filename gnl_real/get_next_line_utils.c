#include <stdlib.h>

int ft_cal_oneline(char *str)
{
    int len;

    len = 0;
    while (*str == '\n' || *str == '\0')
    {
        len++;
        str++;
    }
    if (*str == '\n')
        len++;
    return (len);
}

char    *ft_memcpy(void *dst, void *src, size_t n)
{
    unsigned char   *u_dst;
    unsigned char   *u_src;
    while (n-- > 0)
    {
        *u_dst = *u_src;
        u_dst++;
        u_src++;
    }
    return (dst);
}

char    *ft_calloc(size_t count, size_t size)
{
    char    *output;
    int     index;
    int     len;
    
    len = count * size;
    output = (char *)malloc(len);
    index = 0;
    while (index < len)
    {
        *(output + index) = '\0';
        index++;
    }
    return (output);
}
