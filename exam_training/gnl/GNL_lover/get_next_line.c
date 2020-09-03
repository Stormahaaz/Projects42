/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 14:40:57 by gupatric          #+#    #+#             */
/*   Updated: 2020/09/02 14:40:59 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i++]);
	return (i);
}

char		*ft_strjoin(char *str, char *buff)
{
	char	*rtn;
	int		size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str || !buff)
		return (0);
	size = ft_strlen(str) + ft_strlen(buff);
	if (!(rtn = malloc(sizeof(char) * (size + 1))))
		return (0);
	while (str[j])
		rtn[i++] = str[j++];
	j = 0;
	while (buff[j])
		rtn[i++] = buff[j++];
	rtn[i] = '\0';
	return (rtn);
}

int			ft_strchr(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == c)
			return (1);
	}
	return (0);
}

char		*ft_strdup(char *str, int start, int len)
{
	char	*rtn;
	int		i;

	i = 0;
	if (!str || !(rtn = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start > ft_strlen(str))
		return (NULL);
	while (str[start] && len--)
		rtn[i++] = str[start++];
	rtn[i] = '\0';
	return (rtn);
}


int			ft_fill_it(char	**str, int fd, int ret, char **line)
{
	int		i;
	char *tmp;

	i = -1;
	while (str[fd][++i] != '\n' && str[fd][i]);
	if (str[fd][i] == '\0')
	{
		if (ret == BUFFER_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd], 0, ft_strlen(str[fd]));
		free (str[fd]);
		str[fd] = NULL;
		return (0);
	}
	else if (str[fd][i] == '\n')
	{
		*line = ft_strdup(str[fd], 0, i);
		tmp = ft_strdup(&str[fd][i + 1], 0, ft_strlen(&str[fd][i + 1]));
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
		{
			free(str[fd]);
			str[fd] = NULL;
		}
	}
	return (1);
}

int					get_next_line(int fd, char **line)
{
	static char		*str[255];
	char			buff[BUFFER_SIZE + 1];
	char			*tmp;
	int				ret;

	if (BUFFER_SIZE < 1 || fd < 0 || line == NULL)
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
		if (strchr(buff, '\n'))
			break;
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && str[fd] == NULL)
	{
		*line = malloc(1);
		**line = '\0';
		return (0);
	}
	return (ft_fill_it(str, fd, ret, line));
}