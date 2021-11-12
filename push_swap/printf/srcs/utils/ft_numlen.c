/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:40:18 by gupatric          #+#    #+#             */
/*   Updated: 2020/02/06 18:40:23 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/printf.h"

int	ft_numlen(long int nb)
{
	unsigned int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int	ft_numlen_u(long unsigned int nb)
{
	unsigned int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int	ft_numlen_p(unsigned long long nb, char *base)
{
	unsigned int	size_base;
	int				i;

	i = 1;
	size_base = ft_strlen(base);
	while (nb >= size_base)
	{
		nb /= size_base;
		i++;
	}
	return (i);
}

int	ft_numlen_x(long unsigned int nb, char *base)
{
	unsigned int	size_base;
	int				i;

	i = 1;
	size_base = ft_strlen(base);
	while (nb >= size_base)
	{
		nb /= size_base;
		i++;
	}
	return (i);
}
