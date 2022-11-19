#include "get_next_line.h"
#include <stdlib.h>

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

t_fd_port	*get_last_port(t_fd_port *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}