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

void	ft_apply_conv(char c, t_flags *flags, va_list ap, int *wrtd)
{
	c == 'c' ? ft_print_c(va_arg(ap, int), wrtd, flags) : 0;
	c == 's' ? ft_print_s(wrtd, ap, flags) : 0;
	//c == 'p' ? ft_printhex(wrtd, ap, flags, flags->base, 1) : 0;
	c == 'd' || c == 'i' ? ft_print_d_i(va_arg(ap, int), wrtd, flags) : 0;
	c == 'u' ? ft_print_u(va_arg(ap, unsigned int), wrtd, flags) : 0;
	//c == 'x' ? ft_printhex(wrtd, ap, 0) : 0;
	//c == 'X' ? ft_printhex(wrtd, ap, 0) : 0;
	//c == '%' ? ft_printper(wrtd, flags) : 0;
}
