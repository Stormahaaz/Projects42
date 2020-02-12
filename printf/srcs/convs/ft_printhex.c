/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:51:57 by gupatric          #+#    #+#             */
/*   Updated: 2020/01/21 15:54:24 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>

void				ft_putnbr_base(unsigned int nbr, char *base, size_t *wrtd)
{
	unsigned int	size_base;
	static int		i;

	i = 0;
	size_base = ft_strlen(base);
	if (nbr >= size_base)
	{
		(*wrtd)++;
		ft_putnbr_base(nbr / size_base, base, wrtd);
	}
	ft_putchar(base[nbr % size_base]);
}

void				ft_putnbr_mem(long nbr, char *base, size_t *wrtd)
{
	long		size_base;
	long int	nb;
	static int	i;

	i = 0;
	size_base = ft_strlen(base);
	if (nbr < 0)
	{
		nb = nbr * -1;
		ft_putchar('-');
	}
	else
		nb = nbr;
	if (nb >= size_base)
	{
		*wrtd = *wrtd + 1;
		ft_putnbr_mem(nb / size_base, base, wrtd);
	}
	if (i++ == 0)
	{
		ft_putchar('0');
		ft_putchar('x');
		*wrtd = *wrtd + 2;
	}
	ft_putchar(base[nb % size_base]);
}

void				ft_printhex(size_t *wrtd, va_list ap, char *base, int mem)
{
	long			toprintmem;
	unsigned int	toprinthex;

	if (mem)
	{
		toprintmem = va_arg(ap, long);
		ft_putnbr_mem(toprintmem, base, wrtd);
	}
	else
	{
		toprinthex = va_arg(ap, unsigned int);
		ft_putnbr_base(toprinthex, base, wrtd);
	}
}
