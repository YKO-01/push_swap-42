/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:43:27 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/02/27 13:26:33 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *a, int show)
{
	int	x;
	int	y;

	ft_pop(&x, a);
	ft_pop(&y, a);
	ft_push(x, a);
	ft_push(y, a);
	if (!show)
		ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_stack *b, int show)
{
	int	x;
	int	y;

	ft_pop(&x, b);
	ft_pop(&y, b);
	ft_push(x, b);
	ft_push(y, b);
	if (!show)
		ft_putstr_fd("sb\n", 1);
}

void	swap_ab(t_stack *a, t_stack *b, int show)
{
	int	i;
	int	j;
	int	x;
	int	y;

	ft_pop(&x, a);
	ft_pop(&y, a);
	ft_push(x, a);
	ft_push(y, a);
	ft_pop(&i, b);
	ft_pop(&j, b);
	ft_push(i, b);
	ft_push(j, b);
	if (!show)
		ft_putstr_fd("ss\n", 1);
}
