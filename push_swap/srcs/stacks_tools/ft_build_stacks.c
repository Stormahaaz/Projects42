/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:54:39 by gupatric          #+#    #+#             */
/*   Updated: 2021/11/12 20:54:41 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_build_stack(t_lint **list, char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		ft_lstadd_back_int(list, ft_lstnew_int(ft_atoi(av[i])));
		i++;
	}
}