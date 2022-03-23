#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
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

void	*ft_memmove(void *dst, void *src, size_t len)
{
	unsigned char		*p_dst;
	const unsigned char	*p_src;

	if (dst == 0 && src == 0)
		return (0);
	if (dst > src)
	{
		p_dst = (unsigned char *)(dst + len - 1);
		p_src = (const unsigned char *)(src + len - 1);
		while (len-- > 0)
		{
			*p_dst-- = *p_src--;
		}
	}
	else
	{
		p_dst = (unsigned char *)dst;
		p_src = (const unsigned char *)src;
		while (len-- > 0)
		{
			*p_dst++ = *p_src++;
		}
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++ != 0)
	{
		len++;
	}
	return (len);
}

char	*ft_strjoin(char **s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*result;
	char	*tmp;

	s1_len = ft_strlen(*s1);
	s2_len = 0;
	tmp = s2;
	while (*tmp != '\n' && *tmp != '\0')
	{
		s2_len++;
		tmp++;
	}
	if (*tmp == '\n')
		s2_len++;
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	ft_memcpy(result, *s1, s1_len);
	ft_memcpy(result + s1_len, s2, s2_len + 1);
	free(*s1);
	return (result);
}

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


