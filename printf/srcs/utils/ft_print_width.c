/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:50:55 by gupatric          #+#    #+#             */
/*   Updated: 2020/02/09 18:50:57 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/printf.h"

void	ft_print_width(int *wrtd, t_flags *flags, int len)
{
	if (flags->zero == 1)
		while (flags->width-- > len)
			ft_putchar_pf('0', wrtd);
	else
		while (flags->width-- > len)
			ft_putchar_pf(' ', wrtd);
}
