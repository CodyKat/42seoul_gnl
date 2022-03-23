#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char	*cursor;
	char	*end;
	char	*text;
}	t_list;

char	*get_next_line(int fd);
void	ft_bzero(void *s, size_t n);
int		ft_strlen(char *s, char del);
//char	*ft_calloc(size_t count, size_t size);
//char	*ft_memcpy(void *dst, void *src, size_t n);
char	*ft_strjoin(t_list *node, char *buffer);

#endif
