/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:05:20 by cgoncalv          #+#    #+#             */
/*   Updated: 2019/10/23 19:53:56 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define SUCCESS 1
# define READ_OVER 0
# define ERROR -1

# define BOOL int
# define TRUE 1
# define FALSE 0

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n);

int		get_next_line(int fd, char **line);
int		ft_strchr(const char *str, int c);

size_t	ft_strlen(const char *str);

char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
#endif
