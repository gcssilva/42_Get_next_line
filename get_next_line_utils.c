/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:29:27 by gsilva            #+#    #+#             */
/*   Updated: 2022/11/08 12:31:11 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2, int j)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(ft_strlen(&s1[j]) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1 && s1[j])
		str[i++] = s1[j++];
	while (s2 && *s2)
		str[i++] = *s2++;
	str[i] = 0;
	return (str);
}

char	*ft_read(char **next, int fd)
{
	char	*temp;
	char	*buf;
	int		len;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (1)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len < 1)
			break;
		buf[len] = 0;
		temp = ft_strjoin(*next, NULL, 0);
		if (*next)
			free(*next);
		*next = ft_strjoin(temp, buf, 0);
		free(temp);
		if (ft_strchr(buf, '\n'))
			break;
	}
	free(buf);
	if (!*next)
		return (NULL);
	return (ft_line(next));
}

int		ft_strchr(char *str, int c)
{
	while (*str && *str != c)
		str++;
	if (!str || *str != c)
		return (0);
	return (1);
}

char	*ft_line(char **next)
{
	char	*line;
	char	*temp;
	int		i;
	int		j;
	
	i = 0;
	if (!**next)
		return (NULL);
	while (next[0][i] != '\n' && next[0][i])
		i++;
	if (next[0][i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	j = -1;
	while (++j < i)
		line[j] = next[0][j];
	line[j] = 0;
	temp = ft_strjoin(*next, NULL, i);
	if (*next)
		free(*next);
	*next = ft_strjoin(temp, NULL, 0);
	free(temp);
	return (line);
}