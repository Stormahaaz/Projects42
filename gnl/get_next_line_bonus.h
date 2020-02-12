/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:39:42 by gupatric          #+#    #+#             */
/*   Updated: 2019/11/27 13:41:57 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

void			ft_reset(char **str);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s1);
char			*ft_strchr(const char *s, int c);
int				ft_fill_it(char **str, char **line, int fd, int ret);
size_t			ft_strlen(const char *s1);
int				get_next_line(int fd, char **line);

#endif
