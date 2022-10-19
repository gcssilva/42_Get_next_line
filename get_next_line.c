/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:29:06 by gsilva            #+#    #+#             */
/*   Updated: 2022/10/19 15:10:10 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_free(char *s)
{
	if (!s)
		return ;
	free(s);
	s = NULL;
}

static int	find_nl(char *s, int i)
{
	int	j;

	j = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		i++;
		j++;
	}
	if (s[i] == '\n')
		j++;
	return (j);
}

static char	*ft_line(char **next)
{
	char	*tmp;
	char	*line;
	int		i;

	if (ft_strchr(*next, '\n') == 0)
	{
		line = ft_strdup(*next);
		ft_free(*next);
		*next = ft_strdup("");
	}
	else
	{
		i = find_nl(*next, 0);
		line = ft_substr(*next, 0, i);
		tmp = ft_substr(*next, i, ft_strlen(*next));
		ft_free(*next);
		*next = ft_strdup(tmp);
		ft_free(tmp);
	}
	return (line);
}

static void	ft_read(int fd, char **next)
{
	char	*temp;
	char	*buf;
	int		len;

	buf = (char *)malloc(BUFFER_SIZE +1);
	if (!buf)
		return ;
	len = read(fd, buf, BUFFER_SIZE);
	while (len > 0)
	{
		buf[len] = 0;
		temp = ft_strdup(*next);
		ft_free(*next);
		*next = ft_strjoin(temp, buf);
		ft_free(temp);
		if (ft_strchr(*next, '\n') == 1)
			break ;
		len = read(fd, buf, BUFFER_SIZE);
	}
	ft_free(buf);
}

char	*get_next_line(int fd)
{
	static char	*next = NULL;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	ft_read(fd, &next);
	if (!next || *next == 0)
	{
		ft_free(next);
		return (NULL);
	}
	return (ft_line(&next));
}
