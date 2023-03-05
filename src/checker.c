/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:20:11 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/03/04 13:25:57 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	comparision(char *ptr, char *str, int *ret, int i)
{
	if (ptr[i] == str[i])
		*ret = 1;
	else
	{
		*ret = 0;
		return ;
	}
	if (ptr[i])
		comparision(ptr, str, ret, ++i);
}

int	is_found(char *ptr, char *str)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	comparision(ptr, str, &ret, i);
	free(ptr);
	return (ret);
}

int	get_instraction(char *ptr, t_stack *a, t_stack *b)
{
	if (is_found(ptr, "sa\n"))
		swap_a(a, 1);
	else if (is_found(ptr, "sb\n"))
		swap_b(b, 1);
	else if (is_found(ptr, "pa\n"))
		push_a(a, b, 1);
	else if (is_found(ptr, "pb\n"))
		push_b(a, b, 1);
	else if (is_found(ptr, "ra\n"))
		retate_a(a, b, 1);
	else if (is_found(ptr, "rb\n"))
		retate_b(a, b, 1);
	else if (is_found(ptr, "rra\n"))
		reverse_retate_a(a, b, 1);
	else if (is_found(ptr, "rrb\n"))
		reverse_retate_b(a, b, 1);
	else
		return (ft_putstr_fd("Error\n", 2), FALSE);
	return (TRUE);
}

int	handling_checker(t_stack *a, t_stack *b)
{
	int		ret;
	char	*ptr;

	while (1)
	{
		ptr = get_next_line(0);
		if (!ptr)
			break ;
		if (!get_instraction(ptr, a, b))
			return (free(b->item), free(a->item), free(ptr), FALSE);
	}
	if (b->top >= 0 || a->top != a->size - 1)
		return (free(b->item), free(a->item), ft_putstr_fd("KO\n", 2), FALSE);
	ret = 0;
	stack_sorted(a, b, &ret);
	if (ret)
		return (free(a->item), free(b->item), ft_putstr_fd("KO\n", 2), FALSE);
	free(b->item);
	return (free(a->item), TRUE);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac >= 2)
	{
		create_stack(&a, ++av);
		create_stack(&b, av);
		if (!handling_err(av, &a))
			return (ft_putstr_fd("Error\n", 2), free(b.item), free(a.item), 0);
		if (handling_checker(&a, &b))
			ft_putstr_fd("OK\n", 2);
	}
	return (0);
}
