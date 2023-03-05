/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:46:49 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/03/04 10:15:12 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_2d_array(char **ar)
{
	int	i;

	i = 0;
	while (ar[i])
		free(ar[i++]);
	free(ar);
}

int	fill_array(char **arg, int	*ar, int start)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		ar[start + i] = ft_atoi(arg[i]);
		i++;
	}
	return (i);
}

t_info	find_max(t_stack *s)
{
	int		i;
	t_info	max;

	i = 0;
	max.element = s->item[i];
	max.pos = i;
	while (i < s->top)
	{
		if (max.element < s->item[i + 1])
		{
			max.element = s->item[i + 1];
			max.pos = i + 1;
		}
		i++;
	}
	return (max);
}

t_info	find_min(t_stack *s)
{
	int		i;
	t_info	min;

	i = 0;
	min.element = s->item[i];
	min.pos = i;
	while (i < s->top)
	{
		if (min.element > s->item[i + 1])
		{
			min.element = s->item[i + 1];
			min.pos = i + 1;
		}
		i++;
	}
	return (min);
}

int	*fill_array_sorted_from_stack(t_stack *s)
{
	int	*arr;
	int	i[3];
	int	tmp;

	arr = malloc(s->size * sizeof(int));
	if (!arr)
		return (0);
	i[0] = -1;
	while (++i[0] < s->size - 1)
		arr[i[0]] = s->item[s->top - i[0]];
	i[0] = -1;
	while (++i[0] < s->size - 1)
	{
		i[1] = i[0] + 1;
		while (i[1]++ < s->size - 1)
		{
			if (arr[i[0]] > arr[i[1]])
			{
				tmp = arr[i[0]];
				arr[i[0]] = arr[i[1]];
				arr[i[1]] = tmp;
			}
		}
	}
	return (arr);
}
