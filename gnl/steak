/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 11:26:37 by gupatric          #+#    #+#             */
/*   Updated: 2019/11/28 11:48:01 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s1)
{
	unsigned int	i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}

char	*ft_malloc_it(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = malloc(sizeof(size + 1))))
		return (NULL);
	while (i < size)
		str[i++] = 0;
	str[i] = '\0';
	return (str);
}

int		ft_check_eof(char **line, int fd, int ret, char **str)
{
	if (ret == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
	{
		*line = malloc(1);
		**line = '\0';
	}
	return (0);
}

int		ft_fill_it(char **str, char **line, int fd, int ret)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[fd][i] != '\0' && str[fd][i] != '\n')
		i++;
	if (str[fd][i] == '\0')
	{
		if (ret == BUFFER_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_reset(&str[fd]);
		return (0);
	}
	else if (str[fd][i] == '\n')
	{
		*line = ft_substr(str[fd], 0, i);
		tmp = ft_strdup(str[fd] + i + 1);
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			ft_reset(&str[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*str[255];
	char			buf[BUFFER_SIZE + 1];
	int				ret;
	char			*tmp;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!str[fd])
			str[fd] = ft_malloc_it(1);
		tmp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (ft_check_eof(line, fd, ret, str));
	return (ft_fill_it(str, line, fd, ret));
}

#include <libc.h>
int main(int ac, char **av)
{
	(void)ac;
    char *line;
    int fd = open(av[1], O_RDONLY);
    while (get_next_line(fd, &line) > 0)
	{
        printf("%s\n", line);
		free(line);
	}
}
