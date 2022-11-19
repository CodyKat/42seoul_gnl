#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE

char	*get_next_line(int fd);
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

t_fd_port	*get_last_port(t_fd_port *lst);
#endif
