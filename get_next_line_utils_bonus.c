/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:29:27 by gsilva            #+#    #+#             */
/*   Updated: 2022/11/10 17:43:17 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 1;
	while (str && str[i] && str[i - 1] != '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (*s2 == 0)
		return (NULL);
	i = 0;
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] && s2[j] != '\n')
		str[i++] = s2[j++];
	if (s2[j] == '\n')
		str[i++] = '\n';
	str[i] = 0;
	if (s1)
		free(s1);
	return (str);
}

char	*ft_read(char *next, char *str, int fd)
{
	int		len;

	str = ft_strjoin(str, next);
	if (ft_strchr(next, '\n') > -1)
	{
		ft_strcpy(next, &next[ft_strchr(next, '\n') + 1]);
		return (str);
	}
	while (1)
	{
		len = read(fd, next, BUFFER_SIZE);
		if (len < 1)
			break ;
		next[len] = 0;
		str = ft_strjoin(str, next);
		if (ft_strchr(next, '\n') >= 0)
		{
			ft_strcpy(next, &next[ft_strchr(next, '\n') + 1]);
			return (str);
		}
	}
	ft_strcpy(next, &next[ft_strlen(next)]);
	return (str);
}

int	ft_strchr(char *str, int c)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (!str[i])
		return (-1);
	return (i);
}

void	ft_strcpy(char *dest, char *src)
{
	size_t			i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = 0;
}
