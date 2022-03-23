/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:52:00 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/03/23 19:56:55 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char	*ft_alloced_strnjoin(char *s1, char *s2, size_t len) //
{
	int		s1_len;
	char	*result;

	s1_len = ft_strlen(s1); //
	result = (char *)ft_calloc(sizeof(char), s1_len + len + 1);
	if (result == 0)
	{
		free(s1); // 
		return (0);
	}
	ft_memcpy(result, s1, s1_len); //
	ft_memcpy(result + s1_len, s2, len);
	free(s1); //
	return (result);
}
