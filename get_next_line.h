/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:29:40 by gsilva            #+#    #+#             */
/*   Updated: 2022/10/19 11:55:52 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# ifndef  BUFFER_SIZE
#  define  BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);

char	*ft_strjoin(char *s1, char *s2);

char	*ft_strdup(char *s);

char	*ft_substr(char *s, unsigned int start, int len);

int		ft_strchr(char *str, int c);

int		ft_strlen(char *str);

#endif