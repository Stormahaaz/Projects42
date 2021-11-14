/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:16:33 by gupatric          #+#    #+#             */
/*   Updated: 2021/11/08 16:16:35 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../printf/include/printf.h"
# include "../printf/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_lint
{
	int				content;
	struct s_lint	*next;
}				t_lint;

typedef struct	s_stack
{
	t_lint	*lista;
	t_lint	*listb;
	t_lint	*op_list;
	size_t	b;
}				t_stack;

void	ft_swap_all(t_lint **a, t_lint **b);
void	ft_swap(t_lint **a);
void	ft_build_stack(t_lint **list, char **av);
void	ft_init_stack(t_stack **stacks);
void	ft_rotate(t_lint **list);
t_lint	*ft_lstnew_int(int content);
void	ft_lstadd_back_int(t_lint **alst, t_lint *new);
void	ft_lstpr_int(t_lint **toprint);
void	ft_rev_rotate(t_lint **list);
int		ft_count_int(t_lint **list);


#endif