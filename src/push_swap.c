/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:37:18 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/03/04 10:57:02 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	if (a->size == 3)
		sort_three(a, b);
	else if (a->size <= 5)
		sort_five(a, b);
	else if (a->size > 5)
		sort_for_size(a, b);
	free(b->item);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	int		ret;

	if (ac >= 2)
	{
		create_stack(&a, ++av);
		create_stack(&b, av);
		if (!handling_err(av, &a))
		{
			ft_putstr_fd("Error\n", 2);
			return (free(b.item), free(a.item), 0);
		}
		ret = 0;
		stack_sorted(&a, &b, &ret);
		if (ret == 0)
			return (free(a.item), free(b.item), 0);
		push_swap(&a, &b);
	}
	return (0);
}
