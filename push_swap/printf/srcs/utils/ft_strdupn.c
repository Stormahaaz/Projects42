/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:59:37 by gupatric          #+#    #+#             */
/*   Updated: 2020/02/06 18:59:39 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/printf.h"

char	*ft_strdupn(char *s1, int n)
{
	char	*cpy;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	if (i > n && n != 0)
		i = n;
	cpy = (char *)malloc((i * sizeof(char)) + 1);
	if (!cpy)
		return (0);
	i = -1;
	if (n >= 0)
	{
		while (s1[++i] && i < n)
			cpy[i] = s1[i];
	}
	else
	{
		while (s1[++i])
			cpy[i] = s1[i];
	}
	cpy[i] = '\0';
	return (cpy);
}
