#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
	{
		*(char *)s = '\0';
		s++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}

int	ft_strlen(char *s, char del)
{
	int	len;

	len = 0;
	while (*s != del && *s != '\0')
	{
		len++;
		s++;
	}
	if (*s == '\n')
		len++;
	return (len);
}

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	unsigned char		*p_dst;
	const unsigned char	*p_src;

	if (dst == 0 && src == 0)
		return (0);
	p_dst = dst;
	p_src = src;
	while (n-- > 0)
	{
		*p_dst++ = *p_src++;
	}
	return (dst);
}

char	*ft_strjoin(t_list *node, char *buffer)
{
	int		s1_len;
	int		s2_len;
	char	*result;

	s1_len = node->end - node->text;
	s2_len = ft_strlen(buffer, '\0');
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (result == 0)
		return (0);
	ft_memcpy(result, node->text, s1_len);
	ft_memcpy(result + s1_len, buffer, s2_len + 1);
	//node->cursor = result + s1_len;
	node->end = node->cursor + s1_len + s2_len;
	return (result);
}
