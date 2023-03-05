/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:59:03 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/02/27 13:25:15 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	retate_a(t_stack *a, t_stack *b, int show)
{
	int	first;
	int	e;
	int	i;

	i = 0;
	ft_pop(&first, a);
	while (a->top >= 0)
	{
		ft_pop(&e, a);
		ft_push(e, b);
		i++;
	}
	ft_push(first, a);
	while (i > 0)
	{
		ft_pop(&e, b);
		ft_push(e, a);
		i--;
	}
	if (!show)
		ft_putstr_fd("ra\n", 1);
}

void	retate_b(t_stack *a, t_stack *b, int show)
{
	int	first;
	int	e;
	int	i;

	i = 0;
	ft_pop(&first, b);
	while (b->top >= 0)
	{
		ft_pop(&e, b);
		ft_push(e, a);
		i++;
	}
	ft_push(first, b);
	while (i > 0)
	{
		ft_pop(&e, a);
		ft_push(e, b);
		i--;
	}
	if (!show)
		ft_putstr_fd("rb\n", 1);
}

void	retate_ab(t_stack *a, t_stack *b, int show)
{
	fill_arr(a);
	fill_arr(b);
	if (!show)
		ft_putstr_fd("rr\n", 1);
}

void	fill_arr(t_stack *s)
{
	int	first;
	int	*ar;
	int	i;
	int	j;

	ar = malloc(s->size - 1 * sizeof(int));
	ft_pop(&first, s);
	i = -1;
	j = s->top;
	while (++i <= j)
		ft_pop(&ar[i], s);
	ft_push(first, s);
	while (--i >= 0)
		ft_push(ar[i], s);
	free(ar);
}
