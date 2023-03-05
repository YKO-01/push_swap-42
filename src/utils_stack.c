/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:03:50 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/02/27 13:22:19 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_count(char **arg)
{
	int	i;
	int	j;
	int	word;

	word = 0;
	j = 0;
	while (arg[j])
	{
		i = 0;
		while (arg[j][i])
		{
			if ((arg[j][i + 1] == ' ' || arg[j][i + 1] == 0)
				&& arg[j][i] != ' ')
				word++;
			i++;
		}
		j++;
	}
	return (word);
}

void	fill_stack(int *ar, t_stack *s)
{
	int	i;

	i = s->size;
	while (i-- > 0)
		ft_push(ar[i], s);
}
