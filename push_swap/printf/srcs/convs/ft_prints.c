/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:05:51 by gupatric          #+#    #+#             */
/*   Updated: 2020/01/28 17:05:59 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/printf.h"

void	ft_print_s(int *wrtd, va_list ap, t_flags *flags)
{
	int		i;
	char	*toprint;

	i = -1;
	toprint = va_arg(ap, char *);
	if (!toprint)
		toprint = "(null)";
	if (flags->prec >= 0)
		toprint = ft_strdupn(toprint, flags->prec);
	if (flags->width > (int)ft_strlen(toprint))
		ft_print_s_width(wrtd, flags, toprint, i);
	else
	{
		while (toprint[++i])
			ft_putchar_pf(toprint[i], wrtd);
	}
	if (flags->prec >= 0)
		free(toprint);
}

void	ft_print_s_width(int *wrtd, t_flags *flags, char *toprint, int i)
{
	if (flags->minus == 0)
	{
		while (flags->width-- > (int)ft_strlen(toprint))
		{
			if (!flags->zero)
				ft_putchar_pf(' ', wrtd);
			else
				ft_putchar_pf('0', wrtd);
		}
		while (toprint[++i])
			ft_putchar_pf(toprint[i], wrtd);
	}
	else
	{
		while (toprint[++i])
			ft_putchar_pf(toprint[i], wrtd);
		while (flags->width-- > (int)ft_strlen(toprint))
		{
			if (!flags->zero)
				ft_putchar_pf(' ', wrtd);
			else
				ft_putchar_pf('0', wrtd);
		}
	}
}

void	ft_print_c(int c, int *wrtd, t_flags *flags)
{
	if (flags->minus != 0)
	{
		ft_putchar_pf(c, wrtd);
		while (flags->width-- > 1)
		{
			if (!flags->zero)
				ft_putchar_pf(' ', wrtd);
			else
				ft_putchar_pf('0', wrtd);
		}
	}
	else
	{
		while (flags->width-- > 1)
		{
			if (!flags->zero)
				ft_putchar_pf(' ', wrtd);
			else
				ft_putchar_pf('0', wrtd);
		}
		ft_putchar_pf(c, wrtd);
	}
}
