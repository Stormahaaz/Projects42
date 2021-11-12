/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:28:28 by gupatric          #+#    #+#             */
/*   Updated: 2021/11/04 18:28:32 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list **toprint)
{
	t_list	*liste;

	if (toprint != NULL)
	{
		liste = *toprint;
		while (liste)
		{
			ft_putnbr_fd((int)(liste->content), 1);
			liste = liste->next;
		}
	}
}
