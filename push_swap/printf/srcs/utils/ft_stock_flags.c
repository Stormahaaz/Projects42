/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 12:13:53 by gupatric          #+#    #+#             */
/*   Updated: 2020/02/05 12:13:58 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/printf.h"

void	ft_stock_prec(int *i, const char *format, t_flags *flags, va_list ap)
{
	(*i)++;
	if (format[*i] == '*')
	{
		flags->prec = va_arg(ap, int);
		(*i)++;
	}
	else
	{
		flags->prec = 0;
		while (ft_strchr("0123456789", format[*i]))
			flags->prec = (flags->prec * 10) + (format[(*i)++] - '0');
	}
}

void	ft_stock_width(t_flags *flags, va_list ap)
{
	flags->aste = 1;
	flags->width = va_arg(ap, int);
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->zero = 0;
		flags->width *= -1;
	}
}

void	ft_stock_width_digit(t_flags *flags, char c)
{
	if (flags->aste == 1)
	{
		flags->aste = 0;
		flags->width = 0;
	}
	flags->width = (flags->width * 10) + (c - 48);
}

void	ft_stock_minus(t_flags *flags)
{
	flags->minus = 1;
	flags->zero = 0;
}
