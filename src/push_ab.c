/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:40:22 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/02/27 13:24:46 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack *a, t_stack *b, int show)
{
	int	e;

	ft_pop(&e, a);
	ft_push(e, b);
	if (!show)
		ft_putstr_fd("pb\n", 1);
}

void	push_a(t_stack *a, t_stack *b, int show)
{
	int	e;

	ft_pop(&e, b);
	ft_push(e, a);
	if (!show)
		ft_putstr_fd("pa\n", 1);
}
