#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# define FALSE 0
# define TRUE 1
# define ERROR -1

typedef struct s_word_block
{
	char				*string;
	struct s_word_block	*next;
}	t_word_block;


typedef struct s_fd_port
{
	int					fd;
	struct s_word_block	*head_block;
	struct s_fd_port	*next;
}	t_fd_port;

int	readline(t_fd_port **port, int fd);
int	strcat_newline(char *string1, char *string2);
void	delete_head_word_block(t_fd_port *port);
char	*get_next_line(int fd);
#endif
