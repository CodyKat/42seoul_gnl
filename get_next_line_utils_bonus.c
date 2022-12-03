#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	char	to_find;

	to_find = c;
	while (*s == to_find)
	{
		if (*s == to_find)
			return ((char *)s);
		s++;
	}
	if (to_find == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		src_len;
	const char	*tmp_str = src;

	src_len = 0;
	while (*tmp_str)
	{
		src_len++;
		tmp_str++;
	}
	if (dstsize == 0)
		return (src_len);
	while (--dstsize > 0)
	{
		if (*src == '\0')
			break ;
		*dst++ = *src++;
	}
	*dst = '\0';
	return (src_len);
}
