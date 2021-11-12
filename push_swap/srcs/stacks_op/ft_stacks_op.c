/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:06:38 by gupatric          #+#    #+#             */
/*   Updated: 2021/11/12 20:06:40 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_swap_all(t_lint **a, t_lint **b)
{
	ft_swap(a);
	ft_swap(b);
}

void	ft_swap(t_lint **list)
{
	t_lint	*elem;
	int		tmp;

	elem = *list;
	if (elem == NULL || elem->next == NULL)
		return;
	tmp = elem->next->content;
	elem->next->content = elem->content;
	elem->content = tmp;
}

void	ft_rotate(t_lint **list)
{
	t_lint	*elem;
	t_lint	*tmp;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	tmp = *list;
	*list = (*list)->next;
	elem = *list;
	tmp->next = NULL;
	while (elem->next != NULL)
		elem = elem->next;
	elem->next = tmp;
	
}