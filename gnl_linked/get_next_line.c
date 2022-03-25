/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:44:10 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/03/25 21:41:43 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FD_MAX
# define FD_MAX 256
#endif


typedef struct s_node
{
	t_node	*next;
	t_node	*cur_node;
	char	text[BUFFER_SIZE];
	char	*cursor;
	char	*end_cursor;
	int		oneline_len;
}	t_node;

t_node	**init_table()
{
	t_node	**table;
	int		index;

	index = 0
	table = (t_node **)malloc(sizeof(t_node *) * FD_MAX);
	while (index < FD_MAX)
	{
		
	}
}

char	*get_next_line(int fd)
{
	t_node	**table;

	table = init_table();
}
