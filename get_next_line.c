/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:04:50 by cgoncalv          #+#    #+#             */
/*   Updated: 2019/10/28 16:41:49 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	check_rest(char *s)
{
	size_t i;

	i = 0;
	if (s == NULL)
		return (0);
	while(*s++)
		if (*s == '\n')
			i++;
	return (i);
}

char	*strcut(char *s, size_t size)
{
	char *copy;

	copy = ft_strdup(s);
	free(s);
	if (!(s = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memcpy(s, copy, size + 1);
	s[size] = '\0';
    free(copy);
	return (s);
}

int arrange_rest(int fd, char **rest, char **line)
{
    char    *rest_cpy;
    
    if (rest[fd] != NULL && rest[fd][0] == '\n')
    {
        rest_cpy = ft_strdup(rest[fd]);
        rest[fd] = strcut(rest[fd], 0);
        *line = ft_strjoin(*line, rest[fd]);
        rest[fd] = ft_strdup(&rest_cpy[ft_strchr(rest_cpy, '\n') + 1]);
        free(rest_cpy);
        return (1);
    }
    else if (rest[fd] != NULL && check_rest(rest[fd]) > 0)
    {
        rest_cpy = ft_strdup(rest[fd]);
        rest[fd] = strcut(rest[fd], ft_strchr(rest[fd], '\n'));
        *line = ft_strjoin(*line, rest[fd]);
        rest[fd] = ft_strdup(&rest_cpy[ft_strchr(rest_cpy, '\n') + 1]);
        free(rest_cpy);
        return (1);
    }
    else
    {
        *line = ft_strjoin(*line, rest[fd]);
        rest[fd] = NULL;
        free(rest[fd]);
        return (0);
    }
}

int		get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*rest[OPEN_MAX];
	int				ret;
    
	if (fd < 0 || fd > OPEN_MAX || line == NULL)
		return (-1);
	*line = NULL;
    if (arrange_rest(fd, rest, line) == 1)
        return (1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		*line = ft_strjoin(*line, buff);
		if (ft_strchr(buff, '\n') != -1)
		{
			rest[fd] = ft_strdup(&buff[ft_strchr(buff, '\n') + 1]);
			*line = strcut(*line, ft_strchr(*line, '\n'));
			return (1);
		}
	}
	if (ft_strlen(*line))
		return (1);
	return (ret == -1 ? -1 : 0);
}

/*
int		main(int argc, char *argv[])
{
	char **line;
	line = malloc(sizeof(char*) * 1);
	int fd = open(argv[1], O_RDONLY);
	for (int i = 0 ; i < 8 ; i++)
	{
		get_next_line(fd, line);
		printf("[%i] : %s\n", i, *line);
        free(*line);
	}
}
*/
