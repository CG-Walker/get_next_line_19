/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:04:50 by cgoncalv          #+#    #+#             */
/*   Updated: 2019/10/23 22:29:30 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*

char	*ft_realloc(char *s, char *buff)
{
	char *copy;

	if (buff == NULL)
		return NULL;
	if (s == NULL)
	{
		printf("ENTREE DANS LE IF DE F\n");
		s = ft_strdup(buff);
		return s;
	}
	copy = ft_strdup(s);
	free(s);
	if (!(s = malloc(sizeof(char) * (ft_strlen(copy) + ft_strlen(buff) + 1))))
		return NULL;
	s = ft_strjoin(copy, buff, NULL);
	return s;
}

int		get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	char			*copy;
	static char		*rest = NULL;
	int				ret;

	copy = NULL;
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		printf("Buff : %s\n", buff);
		buff[ret] = '\0';
 		if (ft_strchr(buff, '\n'))
		{
			printf("ENTREE DANS LE IF\n");
			if (!(*line = calloc(sizeof(char), (ft_strlen(rest) + ft_strlen(copy) + ft_strlen(buff) + 1))))
				return (0);
			if (copy == NULL && rest == NULL)
				ft_strlcpy(*line, buff, ft_strlen(buff) + 1);
			else
				*line = ft_strjoin(rest, copy, buff);
			rest = ft_substr(buff, ft_strlen(buff), ft_strlen(&buff[ft_strlen(buff)]) + 1);
			printf("rest : %s\n", rest);
			return (0);
		}
		else
		{
			printf("ENTREE DANS LE ELSE\n");
			copy = ft_realloc(copy, buff);
		}
		printf("FIN DE TOUR DE BOUCLE\n");
	}
	return (0);
}

*/

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

char	*ft_strrealloc(char *s, size_t size)
{
	char *copy;

	copy = ft_strdup(s);
	free(s);
	if (!(s = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memcpy(s, copy, size + 1);
	s[size] = '\0';
	return (s);
}

int		get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*rest = NULL;
	char			*rest_cpy;
	int				ret;

	*line = NULL;
	if (check_rest(rest) > 0)
	{
		rest_cpy = ft_strdup(rest);
		rest = ft_strrealloc(rest, ft_strchr(rest, '\n'));
		*line = ft_strjoin(*line, rest);
		rest = ft_strdup(&rest_cpy[ft_strchr(rest_cpy, '\n') + 1]);
		return (1);
	}
	else
	{
		*line = ft_strjoin(*line, rest);
	}
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		*line = ft_strjoin(*line, buff);
		if (ft_strchr(buff, '\n') != -1)
		{
			rest = ft_strdup(&buff[ft_strchr(buff, '\n') + 1]);
			*line = ft_strrealloc(*line, ft_strchr(*line, '\n'));
			return (1);
		}
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	char **line;
	line = malloc(sizeof(char*) * 1);
	int fd = open(argv[1], O_RDONLY);
	for (int i = 0 ; i < 5 ; i++)
	{
		get_next_line(fd, line);
		printf("[%i] : %s\n", i, *line);
	}
}
