/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:01:26 by gupatric          #+#    #+#             */
/*   Updated: 2019/12/04 14:01:27 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"

void	ft_init_params(t_flags *flags)
{
	flags->zero = 0;
	flags->prec = -1;
	flags->width = 0;
	flags->type = 0;
	flags->aste = 0;
	flags->minus = 0;
	flags->type = 0;
	flags->base = "0123456789abcdef";
	flags->mod = 0;
}

void	ft_get_params(int *i, const char *format, t_flags *flags, va_list ap)
{
	while (format[*i + 1] && ft_strchr("-0.*123456789lhcspdiuxX%",
			format[++*i]))
	{
		if (format[*i] == '0' && flags->minus == 0 && flags->width == 0)
			flags->zero = 1;
		if (format[*i] == '.')
			ft_stock_prec(i, format, flags, ap);
		if (format[*i] == '-')
			ft_stock_minus(flags);
		if (format[*i] == '*')
			ft_stock_width(flags, ap);
		if (ft_strchr("0123456789", format[*i]))
			ft_stock_width_digit(flags, format[*i]);
		while (ft_strchr("cspdiuxXhl%", format[*i]))
		{
			flags->type = (char *)&format[*i];
			if (ft_strchr("hl", format[*i])
				&& ft_strchr("diuxX", format[*i + 1]))
				++*i;
			return ;
		}
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_flags	flags;
	int		i;
	int		wrtd;

	va_start(ap, format);
	i = -1;
	wrtd = 0;
	while (format[++i])
	{
		ft_init_params(&flags);
		if (format[i] == '%' && format[i + 1])
		{
			ft_get_params(&i, format, &flags, ap);
			if (ft_strchr("cspdiuxX%lh", format[i]))
				ft_apply_conv(flags.type, &flags, ap, &wrtd);
			else
				ft_putchar_pf(format[i], &wrtd);
		}
		else
			ft_putchar_pf(format[i], &wrtd);
	}
	va_end(ap);
	return (wrtd);
}
