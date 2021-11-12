/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 09:29:29 by ccorsin           #+#    #+#             */
/*   Updated: 2018/04/18 17:48:35 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_pile		*ft_pilenew(int n)
{
	t_pile		*new;

	if (!(new = (t_pile *)malloc(sizeof(*new))))
		exit(0);
	new->data = n;
	new->next = NULL;
	return (new);
}

t_begin		*ft_init_begin(void)
{
	t_begin		*begin;

	if (!(begin = (t_begin*)malloc(sizeof(t_begin))))
		exit(1);
	ft_bzero(begin, sizeof(t_begin));
	return (begin);
}

void		ft_lstdel2(t_pile **begin)
{
	t_pile	*tmp;

	while (*begin != NULL)
	{
		tmp = (*begin)->next;
		free(*begin);
		*begin = tmp;
	}
	free(*begin);
}
