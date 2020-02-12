/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:11:06 by gupatric          #+#    #+#             */
/*   Updated: 2020/01/28 17:37:22 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
#define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

typedef struct	s_flags
{
	int			width;
	int			prec;
	int			minus;
	char		type;
	int			aste;
	int			zero;
	char		*base;
}				t_flags;

/*
** Functions wich allow parsing
*/

void	ft_stock_prec(int *i, const char *format, t_flags *flags, va_list ap);
void	ft_stock_width(t_flags *flags, va_list ap);
void	ft_stock_width_digit(t_flags *flags, char c);
void	ft_stock_minus(t_flags *flags);
void	ft_get_params(int *i, const char *format, t_flags *flags, va_list ap);
void	ft_init_params(t_flags *flags);
int		ft_strchr(const char *s, int c);
void	ft_print_width(int *wrtd, t_flags *flags, int len);
size_t	ft_strlen(const char *s);

/*
** Functions wich allow the display of data
*/

void	ft_putchar_pf(char c, int *wrtd);
void	ft_print_s(int *wrtd, va_list ap, t_flags *flags);
void	ft_print_c(int c, int *wrtd, t_flags *flags);
void	ft_print_d_i(int nb, int *wrtd, t_flags *flags);
void	ft_apply_conv(char c, t_flags *flags, va_list ap, int *wrtd);

/*
** Functions wich works with ft_printd_i/ft_print_u
*/

void	ft_putnbr_pf_u(unsigned int nb, int *wrtd);
void	ft_print_u(unsigned int nb, int *wrtd, t_flags *flags);
int		ft_numlen(int nb);
int		ft_numlen_u(unsigned int nb);
void	ft_putnbr_pf(int nb, int *wrtd);

/*
** functions wich works only with ft_prints
*/

void	ft_print_s_width(int *wrtd, t_flags *flags, char *toprint, int i);

/*
** Useful functions for converting data
*/

int		ft_numlen(int nb);
char	*ft_strdupn(char *s1, int n);
size_t	ft_strlen(const char *s);

int		ft_printf(const char *format, ...);

#endif