/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:05:09 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/03/28 11:05:18 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef FD_MAX
#  define FD_MAX 256
# endif
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_strchr(char *str, char to_find);
void	*ft_memcpy(void *dst, void *src, size_t n);
char	*ft_strjoin(char **p_s1, char *s2);
int		in_newline(char *str);

#endif
