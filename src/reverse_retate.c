/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_retate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 01:24:19 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/02/25 17:30:00 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_retate_a(t_stack *a, t_stack *b, int show)
{
	int	last;
	int	e;
	int	i;

	i = 0;
	while (a->top > 0)
	{
		ft_pop(&e, a);
		ft_push(e, b);
		i++;
	}
	ft_pop(&last, a);
	while (i > 0)
	{
		ft_pop(&e, b);
		ft_push(e, a);
		i--;
	}
	ft_push(last, a);
	if (!show)
		ft_putstr_fd("rra\n", 1);
}

void	reverse_retate_b(t_stack *a, t_stack *b, int show)
{
	int	last;
	int	e;
	int	i;

	i = 0;
	while (b->top > 0)
	{
		ft_pop(&e, b);
		ft_push(e, a);
		i++;
	}
	ft_pop(&last, b);
	while (i > 0)
	{
		ft_pop(&e, a);
		ft_push(e, b);
		i--;
	}
	ft_push(last, b);
	if (!show)
		ft_putstr_fd("rrb\n", 1);
}

void	reverse_retate(t_stack *a, t_stack *b, int show)
{
	reverse_stack(a, b);
	reverse_stack(b, a);
	if (!show)
		ft_putstr_fd("rrr\n", 1);
}

void	reverse_stack(t_stack *s, t_stack *p)
{
	int	last;
	int	e;
	int	i;

	i = 0;
	while (s->top > 0)
	{
		ft_pop(&e, s);
		ft_push(e, p);
		i++;
	}
	ft_pop(&last, s);
	while (i > 0)
	{
		ft_pop(&e, p);
		ft_push(e, s);
		i--;
	}
	ft_push(last, s);
}
