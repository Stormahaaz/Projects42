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

void	ft_rev_rotate(t_lint **list)
{
	t_lint	*elem;
	int		tmp;
	int		i;
	int		j;

	i = ft_count_int(list) - 1;
	if (*list == NULL || (*list)->next == NULL)
		return ;
	elem = *list;
	while (elem->next)
		elem = elem->next;
	tmp = elem->content;
	while (i)
	{
		elem = *list;
		j = 1;
		while (j < i)
		{
			elem = elem->next;
			j++;
		}
		elem->next->content = elem->content;
		i--;
	}
	(*list)->content = tmp;
}