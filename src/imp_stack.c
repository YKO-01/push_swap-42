/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imp_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:39:50 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/03/03 19:40:26 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack(t_stack *p, char **arg)
{
	p->top = -1;
	p->size = arg_count(arg);
	p->item = malloc(p->size * sizeof(int));
	if (!p->item)
		return ;
}

void	ft_push(int e, t_stack *p)
{
	if (!stack_full(p))
	{
		p->top++;
		p->item[p->top] = e;
	}
}

void	ft_pop(int *e, t_stack *p)
{
	if (!stack_empty(p))
		*e = p->item[(p->top)--];
}

int	stack_empty(t_stack *p)
{
	return (!(p->top + 1));
}

int	stack_full(t_stack *p)
{
	return (!(p->top - (p->size - 1)));
}

/*
void	ft_print(t_stack *s)
{
	int tmp;

	if (s->top == -1)
		return;
	ft_pop(&tmp, s);
	printf("%d\n", tmp);
	ft_print(s);
	ft_push(tmp, s);
}*/
