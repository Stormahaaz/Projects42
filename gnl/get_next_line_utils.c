/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:46:57 by gupatric          #+#    #+#             */
/*   Updated: 2019/11/22 16:47:00 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	while (*s1)
		str[i++] = *(s1++);
	while (*s2)
		str[i++] = *(s2++);
	str[i] = '\0';
	return (str);
}

void		ft_reset(char **str)
{
	free(*str);
	*str = NULL;
	return ;
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*cpy;

	i = 0;
	if (!s || !(cpy = malloc(((len + 1) * sizeof(char)))))
		return (0);
	if (start > ft_strlen(s))
	{
		cpy[0] = '\0';
		return (cpy);
	}
	while (i < len && s[start])
	{
		cpy[i] = s[start];
		i++;
		start++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char		*ft_strdup(const char *s1)
{
	char	*cpy;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	if (!(cpy = (char *)malloc((i * sizeof(char)) + 1)))
		return (0);
	i = -1;
	while (s1[++i])
		cpy[i] = s1[i];
	cpy[i] = '\0';
	return (cpy);
}

char		*ft_strchr(const char *s, int c)
{
	if (c == 0)
	{
		while (*s)
			s++;
		return ((char*)s);
	}
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char*)s);
		s++;
	}
	return (0);
}
