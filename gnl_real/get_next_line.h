#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	char	*text;
	char	*cursor;
	char	*end;
	int 	status;
	int	node_len;
	int	oneline_len;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

int	ft_cal_oneline(char * str);
char	*ft_memcpy(void	*dst, void *src, size_t n);
char	*ft_calloc(size_t count, size_t size);

#endif
