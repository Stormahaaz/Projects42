/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 11:55:41 by gupatric          #+#    #+#             */
/*   Updated: 2019/12/13 11:55:43 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/printf.h"

void	ft_apply_conv(char *c, t_flags *flags, va_list ap, int *wrtd)
{
	if (*c == 'c')
		ft_print_c(va_arg(ap, int), wrtd, flags);
	if (*c == 's')
		ft_print_s(wrtd, ap, flags);
	if (*c == 'p')
		ft_print_p(wrtd, va_arg(ap, unsigned long long), flags);
	if (*c == 'd' || *c == 'i')
		ft_print_d_i(va_arg(ap, long int), wrtd, flags);
	if (*c == 'u')
		ft_print_u(va_arg(ap, long unsigned int), wrtd, flags);
	ft_apply_cvn(c, flags, ap, wrtd);
}

void	ft_apply_cvn(char *c, t_flags *flags, va_list ap, int *wrtd)
{
	if (*c == 'x' || *c == 'X')
	{
		if (*c == 'X')
			flags->base = "0123456789ABCDEF";
		ft_print_hex(wrtd, va_arg(ap, long unsigned int), flags);
	}
	if (*c == 'l' && ft_strchr("diuxX", *(c + 1)))
	{
		flags->mod = *c;
		ft_apply_conv(c + 1, flags, ap, wrtd);
	}
	if (*c == 'h' && ft_strchr("diuxX", *(c + 1)))
	{
		flags->mod = *c;
		ft_apply_conv(c + 1, flags, ap, wrtd);
	}
	if (*c == '%')
		ft_print_c('%', wrtd, flags);
}
