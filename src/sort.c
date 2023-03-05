/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:38:51 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/03/04 22:48:42 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a, t_stack *b)
{
	int	i;

	i = a->top;
	while (i >= 0 && (a->item[i] > a->item[i - 1]))
		i--;
	if (i == -1 || (a->item[2] > a->item[1] && a->item[1] > a->item[0]))
	{
		swap_a(a, 0);
		reverse_retate_a(a, b, 0);
	}
	else if (a->item[2] > a->item[0] && a->item[2] > a->item[1]
		&& a->item[1] < a->item[0])
		retate_a(a, b, 0);
	else if (a->item[2] < a->item[0] && a->item[2] > a->item[1])
		swap_a(a, 0);
	else if (a->item[2] < a->item[1] && a->item[2] > a->item[0])
		reverse_retate_a(a, b, 0);
	else if (a->item[a->top - 1] > a->item[a->top]
		&& a->item[0] < a->item[a->top - 1])
	{
		reverse_retate_a(a, b, 0);
		swap_a(a, 0);
	}
}

void	sort_five(t_stack *a, t_stack *b)
{
	t_info	min;
	int		midl;

	while (a->top > 2)
	{
		midl = (a->top + 1) / 2;
		min = find_min(a);
		if (min.pos == a->top)
			push_b(a, b, 0);
		else if (min.pos < midl)
			reverse_retate_a(a, b, 0);
		else if (min.pos > midl || min.pos == midl)
			retate_a(a, b, 0);
	}
	sort_three(a, b);
	while (b->top >= 0)
		push_a(a, b, 0);
}

void	sort_for_size(t_stack *a, t_stack *b)
{
	int	*ar;
	int	range;
	int	index;

	ar = fill_array_sorted_from_stack(a);
	range = 0.05 * a->size + 10;
	while (a->top >= 0)
	{
		index = get_index(a, ar);
		if (index < b->top + 2)
		{
			push_b(a, b, 0);
			retate_b(a, b, 0);
		}
		else if (index >= b->top + 1 && index <= b->top + 1 + range)
			push_b(a, b, 0);
		else
			retate_a(a, b, 0);
	}
	free(ar);
	continue_sort(a, b);
}

int	get_index(t_stack *s, int *array)
{
	int	len;

	len = 0;
	while (len < s->size)
	{
		if (array[len] == s->item[s->top])
			return (len);
		len++;
	}
	return (len);
}

void	continue_sort(t_stack *a, t_stack *b)
{
	t_info	max;
	int		midl;

	midl = (b->top + 1) / 2;
	max = find_max(b);
	if (max.pos == b->top)
		push_a(a, b, 0);
	else if (max.pos < midl)
		reverse_retate_b(a, b, 0);
	else if (max.pos >= midl)
		retate_b(a, b, 0);
	if (b->top >= 0)
		continue_sort(a, b);
}
