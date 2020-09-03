/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 10:36:12 by gupatric          #+#    #+#             */
/*   Updated: 2020/09/02 12:11:53 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int                     ft_strlen(char *str)
{
    int                 i = -1;

    while (str[++i]);
    return (i);
}

char                    *ft_strjoin(char *str, char *buff)
{
    int                 size;
    char                *string;
    int                 i;

    i = -1;
    if (!str || !buff)
        return (NULL);
    size = ft_strlen(str) + ft_strlen(buff);
    if (!(string = malloc(sizeof(char) * size + 1)))
        return (NULL);
    while (*str)
        string[++i] = *(str++);
    while (*buff)
        string[++i] = *(buff++);
    string[++i] = '\0';
    return (string);
}

int                     ft_strchr(char *str, char c)
{
    while (*str)
        if (*(str++) == c)
            return (1);
    return (0);
}

char                    *ft_strdup(char *str, int start, int len)
{
    int                 i;
    char                *cpy;

    i = 0;
    if (!str || !(cpy = malloc(sizeof(char) * (len + 1))))
        return (NULL);
    if (start > ft_strlen(str))
        return (cpy = NULL);
    str = &str[start];
    while (*str && i < len)
        cpy[i++] = *(str++);
    cpy[i] = '\0';
    return (cpy);
}

int                     ft_fill_it(char **str, char **line, int ret, int fd)
{   
    int                 i;
    char                *tmp;

    i = -1;
    while ((*str)[++i] != '\0' && (*str)[i] != '\n');
    if ((*str)[i] == '\0')
    {
        if (ret == BUFFER_SIZE)
            return (get_next_line(fd, line));
        *line = ft_strdup(*str, 0, ft_strlen(*str));
        free (*str);
        *str = NULL;
        return (0);
    }
    else if ((*str)[i] == '\n')
    {
       // printf(">||string after the '\\n' = \n%s||<", &(*str)[i + 1]);
        *line = ft_strdup(*str, 0, i);
        tmp = ft_strdup(*str, i + 1, ft_strlen((&(*str)[i + 1])));
        free (*str);
        *str = tmp;
        if ((*str)[0] == '\0')
        {
            free (*str);
            *str = NULL;
        }
    }
    return (1);
}

int                     get_next_line(int fd, char **line)
{
    static char         *str[255];
    char                *tmp;
    char                buff[BUFFER_SIZE + 1];
    int                 ret;
	
	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
    while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
    {
        buff[ret] = '\0';
        if (!str[fd])
        {
            if (!(str[fd] = malloc(1)))
                return (-1);
            str[fd][0] = '\0';
        }
		tmp = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
    }
    if (ret < 0)
        return (-1);
    if (ret == 0 && !str[fd])
    {
        *line = malloc(1);
        **line = '\0';
        return (0);
    }
    return (ft_fill_it(&str[fd], line, ret, fd));
}
