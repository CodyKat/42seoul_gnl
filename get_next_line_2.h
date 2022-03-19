/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:51:49 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/03/19 21:55:15 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str);

void	*ft_calloc(size_t count, size_t size);
void	*ft_bzero(void *s, size_t n);
char	*ft_strjoin(char **s1, char *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);