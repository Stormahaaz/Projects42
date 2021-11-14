/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stacks_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 05:07:05 by gupatric          #+#    #+#             */
/*   Updated: 2021/11/14 05:07:07 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_count_int(t_lint **list)
{
	int		i;
	t_lint 	*elem;

	elem = *list;
	i = 0;
	while (elem->next)
	{
		elem = elem->next;
		i++;
	}
	return (++i);
}