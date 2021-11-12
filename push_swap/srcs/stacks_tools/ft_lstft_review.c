/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstft_review.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 23:28:28 by gupatric          #+#    #+#             */
/*   Updated: 2021/11/12 23:28:31 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_lint	*ft_lstnew_int(int content)
{
	t_lint	*new;

	new = (t_lint *)malloc(sizeof(*new) * 1);
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_int(t_lint **alst, t_lint *new)
{
	t_lint	*tmp;

	tmp = *alst;
	if (alst)
	{
		if (!*alst)
			*alst = new;
		else
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
}

void	ft_lstpr_int(t_lint **toprint)
{
	t_lint	*liste;

	if (toprint != NULL)
	{
		liste = *toprint;
		while (liste)
		{
			ft_putnbr_fd(liste->content, 1);
			liste = liste->next;
		}
	}
}