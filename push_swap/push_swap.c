/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:01:57 by gupatric          #+#    #+#             */
/*   Updated: 2021/11/02 19:01:58 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

void	ft_init_stack(t_stack **stacks)
{
	*stacks = (t_stack *)malloc(sizeof(t_stack));
	if (!*stacks)
		exit(1);
	ft_bzero(*stacks, sizeof(t_stack));
	
}

int main(int ac, char **av)
{
	t_stack *stacks;

	if (!ac || !av[1])
		return (0);
	ft_init_stack(&stacks);
	ft_build_stack(&stacks->lista, av);
	ft_rotate(&stacks->lista);
	ft_lstpr_int(&stacks->lista);
	return (0);
}