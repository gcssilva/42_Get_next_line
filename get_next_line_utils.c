/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:29:27 by gsilva            #+#    #+#             */
/*   Updated: 2022/10/19 12:45:23 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1 && *s1)
		str[i++] = *s1++;
	while (s2 && *s2)
		str[i++] = *s2++;
	str[i] = 0;
	return (str);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*dup;

	if (!s)
		return (ft_strdup(""));
	i = 0;
	dup = (char *)malloc(ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	while (*s)
	{
		dup[i] = *s;
		i++;
		s++;
	}
	dup[i] = 0;
	return (dup);
}

int	ft_strchr(char *str, int c)
{
	while (*str && *str != c)
		str++;
	if (!str || *str != c)
		return (0);
	return (1);
}

char	*ft_substr(char *s, unsigned int start, int len)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
		str[i++] = s[start++];
	str[i] = 0;
	return (str);
}
