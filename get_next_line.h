/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:29:40 by gsilva            #+#    #+#             */
/*   Updated: 2022/11/08 12:36:17 by gsilva           ###   ########.fr       */
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

char	*ft_strjoin(char **s1, char *s2, int j);

char	*ft_line(char **next);

int		ft_strchr(char *str, int c);

int		ft_strlen(char *str);

char	*ft_read(char **next, int fd);

#endif