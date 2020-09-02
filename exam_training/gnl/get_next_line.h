/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 14:47:28 by gupatric          #+#    #+#             */
/*   Updated: 2020/08/25 14:47:30 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int         get_next_line(int fd, char **line);
int         ft_fill_it(char **str, char **line, int ret, int fd);
char        *ft_strjoin(char   *str, char *buff);
int         ft_strlen(char *str);
int         ft_strchr(char *str, char c);
//char        *ft_strdup(char *str, int start, int len);

#endif