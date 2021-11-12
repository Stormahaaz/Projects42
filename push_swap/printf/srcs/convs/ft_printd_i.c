/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:40:03 by gupatric          #+#    #+#             */
/*   Updated: 2020/02/10 12:40:04 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/printf.h"

void	ft_print_d_i(long int nb, int *wrtd, t_flags *flags)
{
	int	numlen;

	if (flags->mod == 0)
		nb = (int)nb;
	if (flags->mod == 'h')
		nb = (short)nb;
	numlen = ft_numlen(nb);
	if (flags->zero && flags->prec > -1)
		flags->zero = 0;
	if (flags->prec > numlen && nb < 0)
		numlen = flags->prec + 1;
	else
		if (nb < 0)
			numlen += 1;
	if (flags->prec > numlen)
		numlen = flags->prec;
	if (flags->zero && nb < 0)
		ft_putchar_pf('-', wrtd);
	if (flags->prec == 0 && nb == 0)
		flags->width++;
	ft_print_d_i_n(nb, wrtd, flags, numlen);
}

void	ft_putnbr_pf(long int nb, int *wrtd)
{
	long unsigned int	sign;

	if (nb < 0)
		sign = nb * -1;
	else
		sign = nb;
	if (sign > 9)
		ft_putnbr_pf(sign / 10, wrtd);
	ft_putchar_pf(sign % 10 + '0', wrtd);
}

void	ft_print_u(long unsigned int nb, int *wrtd, t_flags *flags)
{
	int	numlen;

	if (flags->type[0] == 'u')
		nb = (unsigned int)nb;
	if (flags->type[0] == 'h')
		nb = (short unsigned int)nb;
	numlen = ft_numlen_u(nb);
	if (flags->zero && flags->prec != -1)
		flags->zero = 0;
	if (flags->prec > numlen)
		numlen = flags->prec;
	if (flags->prec == 0 && nb == 0)
		flags->width++;
	if (!flags->minus)
		ft_print_width(wrtd, flags, numlen);
	while (flags->prec-- > ft_numlen_u(nb))
		ft_putchar_pf('0', wrtd);
	if (!(flags->prec == -1 && nb == 0))
		ft_putnbr_pf_u(nb, wrtd);
	ft_print_width(wrtd, flags, numlen);
}

void	ft_putnbr_pf_u(long unsigned int nb, int *wrtd)
{
	long unsigned int	sign;

	sign = nb;
	if (sign > 9)
		ft_putnbr_pf(sign / 10, wrtd);
	ft_putchar_pf(sign % 10 + '0', wrtd);
}

void	ft_print_d_i_n(long int nb, int *wrtd, t_flags *flags, int numlen)
{
	if (!flags->minus)
		ft_print_width(wrtd, flags, numlen);
	if (nb < 0 && flags->zero == 0)
		ft_putchar_pf('-', wrtd);
	while (flags->prec-- > ft_numlen(nb))
		ft_putchar_pf('0', wrtd);
	if (!(flags->prec == -1 && nb == 0))
		ft_putnbr_pf(nb, wrtd);
	ft_print_width(wrtd, flags, numlen);
}
