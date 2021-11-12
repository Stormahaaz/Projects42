/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:19:23 by gupatric          #+#    #+#             */
/*   Updated: 2020/02/19 13:19:26 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/printf.h"

void	ft_print_hex(int *wrtd, long unsigned int nb, t_flags *flags)
{
	int	numlen;

	if (flags->mod == 0)
		nb = (unsigned int)nb;
	if (flags->mod == 'h')
		nb = (short unsigned int)nb;
	numlen = ft_numlen_x(nb, flags->base);
	if (flags->zero && flags->prec != -1)
		flags->zero = 0;
	if (flags->prec > numlen)
		numlen = flags->prec;
	if (flags->prec == 0 && nb == 0)
		flags->width++;
	if (!flags->minus)
		ft_print_width(wrtd, flags, numlen);
	while (flags->prec-- > ft_numlen_x(nb, flags->base))
		ft_putchar_pf('0', wrtd);
	if (!(flags->prec == -1 && nb == 0))
		ft_putnbr_hex(nb, flags->base, wrtd);
	ft_print_width(wrtd, flags, numlen);
}

void	ft_putnbr_hex(long unsigned int nbr, char *base, int *wrtd)
{
	if (nbr >= 16)
		ft_putnbr_hex(nbr / 16, base, wrtd);
	ft_putchar_pf(base[nbr % 16], wrtd);
}
