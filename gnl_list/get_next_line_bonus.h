#ifndef GET_NEXT_LINE_H
# include <stdlib.h>
# define GET_NEXT_LINE_H
# define FALSE 0
# define TRUE 1
# define ERROR -1

typedef struct s_word
{
	char			*string;
	int				start_idx;
	struct s_word	*next;
}	t_word;

typedef struct s_fd_port
{
	int					fd;
	struct s_fd_port	*next;
	t_word				*head_word;
}	t_fd_port;

typedef struct s_line_info
{
	int	reserve_block_size;
	int	len_tail;
}	t_line_info;


char		*get_next_line(int fd);
t_fd_port	*get_last_port(t_fd_port *lst);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
#endif
