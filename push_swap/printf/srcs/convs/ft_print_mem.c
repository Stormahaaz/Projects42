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

#include "../../include/printf.h"
#include <stdio.h>

void	ft_print_p(int *wrtd, unsigned long long nb, t_flags *flags)
{
	int	numlen;

	numlen = 5;
	if (nb)
		numlen = ft_numlen_p(nb, flags->base) + 2;
	if (nb == 0 && flags->prec != -1)
		numlen--;
	if (flags->zero && flags->prec != -1)
		flags->zero = 0;
	if (flags->prec > numlen)
		numlen = flags->prec;
	if (!flags->minus)
		ft_print_width(wrtd, flags, numlen);
	if (nb)
	{	
		ft_putchar_pf('0', wrtd);
		ft_putchar_pf('x', wrtd);
	}
	if (flags->prec != -1 && nb == 0)
		flags->prec++;
	while (flags->prec-- > ft_numlen_p(nb, flags->base))
		ft_putchar_pf('0', wrtd);
	ft_putnbr_mem(nb, flags, wrtd);
	ft_print_width(wrtd, flags, numlen);
}

void	ft_putnbr_mem(unsigned long long nbr, t_flags *flags, int *wrtd)
{
	unsigned int	size_base;

	size_base = ft_strlen(flags->base);
	if (nbr)
	{	
		if (nbr >= size_base)
			ft_putnbr_mem(nbr / size_base, flags, wrtd);
		if (nbr == 0 && flags->prec != -1)
			return ;
		ft_putchar_pf(flags->base[nbr % size_base], wrtd);
	}
	else
	{
		write(1, "(nil)", 5);
		*wrtd += 5;
	}
}
