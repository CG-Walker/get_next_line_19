/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:05:11 by cgoncalv          #+#    #+#             */
/*   Updated: 2019/10/23 19:53:59 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	if (s == NULL)
		return (0);
	while (*s++)
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	i;

	i = -1;
	if (!(copy = malloc((sizeof(char) * ft_strlen(s1)) + 1)))
		return (NULL);
	while (++i < ft_strlen(s1))
		copy[i] = s1[i];
	copy[i] = '\0';
	return (copy);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < n && (dst != NULL || src != NULL))
	{
		((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *ret;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (!(ret = malloc((sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1))))
		return (NULL);
	if (s1 != NULL)
	{
		ft_memcpy(ret, s1, ft_strlen(s1));
		ft_memcpy(&ret[ft_strlen(s1)], s2, ft_strlen(s2) + 1);
	}
	else
		ft_memcpy(ret, s2, ft_strlen(s2) + 1);
	return (ret);
}

int		ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (i < ft_strlen(s))
	{
		if (c == s[i])
			return (i);
		i++;
	}
	if (c == s[i])
		return (i);
	return (-1);
}
