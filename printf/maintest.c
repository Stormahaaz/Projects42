/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:56:21 by gupatric          #+#    #+#             */
/*   Updated: 2020/02/06 18:27:50 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"
#include <stdlib.h>

unsigned int	ft_atoi_u(char *str)
{
	unsigned int rtn;

	rtn = 0;
	while (*str && (*str <= '9' && *str >= '0'))
		rtn = rtn * 10 + (*(str++) - 48);
	return (rtn);
}

int		main(int ac, char **av)
{
	char	*str;
	char	c;
	int		ft_pf;
	int		pf;
	int		prec;
	int		width;

	c = 'c';
	str = "hello";

	pf = printf("%11x\n", 10);
	fflush(stdout);
	ft_pf = ft_printf("%11x\n", 10);	
	if (pf == ft_pf)
		printf("returned value is ok.\n");
	else
		return (printf("returned by printf = %d, returned by ft_printf = %d\n", pf, ft_pf));
	printf("returned by printf = %d, returned by ft_printf = %d\n", pf, ft_pf);
	return (0);
}
