/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:40:18 by gupatric          #+#    #+#             */
/*   Updated: 2020/02/06 18:40:23 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_numlen(int nb)
{
	unsigned int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int		ft_numlen_u(unsigned int nb)
{
	unsigned int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}
