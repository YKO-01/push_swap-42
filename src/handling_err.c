/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_err.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:04:53 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/03/04 10:50:05 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg(char **arg)
{
	int		i;
	int		j;
	long	num;

	i = 0;
	while (arg[i])
	{
		j = 0;
		if (arg[i][j] == '-' || arg[i][j] == '+')
			j++;
		if (arg[i][j] == 0)
			return (FALSE);
		while (arg[i][j])
		{
			if (arg[i][j] < '0' || arg[i][j] > '9')
				return (FALSE);
			j++;
		}
		num = ft_atoi(arg[i]);
		if (num > 2147483647 || num < -2147483648)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	handling_duplicate(int	*ar, t_stack *s)
{
	int	i;
	int	j;

	i = 0;
	while (i < s->size)
	{
		j = i + 1;
		while (j < s->size)
		{
			if (ar[i] != ar[j])
				j++;
			else
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

void	stack_sorted(t_stack *a, t_stack *b, int *ret)
{
	int	e;

	if (a->top > 0)
	{
		ft_pop(&e, a);
		ft_push(e, b);
		if (a->item[a->top] < b->item[b->top])
			*ret = 1;
		if (a->top > 0)
			stack_sorted(a, b, ret);
		ft_pop(&e, b);
		ft_push(e, a);
	}
}

int	handling_err(char **arg, t_stack *s)
{
	char	**argument;
	int		*ar;
	int		i;
	int		j;

	ar = malloc(s->size * sizeof(int));
	i = 0;
	j = 0;
	while (arg[i])
	{
		argument = ft_split(arg[i], ' ');
		if (!*argument)
			return (free_2d_array(argument), free(ar), FALSE);
		if (!check_arg(argument))
			return (free_2d_array(argument), free(ar), FALSE);
		j += fill_array(argument, ar, j);
		free_2d_array(argument);
		i++;
	}
	if (!handling_duplicate(ar, s))
		return (free(ar), FALSE);
	return (fill_stack(ar, s), free(ar), TRUE);
}
