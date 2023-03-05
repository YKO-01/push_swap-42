/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:39:10 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/03/05 11:50:56 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define FALSE 0
# define TRUE 1

typedef struct s_stack
{
	int	top;
	int	size;
	int	*item;
}	t_stack;

typedef struct s_info
{
	int	element;
	int	pos;
}	t_info;

//	==============================
//	=		main functions		 =
//	==============================

void	stack_sorted(t_stack *a, t_stack *b, int *ret);
void	push_swap(t_stack *a, t_stack *b);

// ==============================
// =		handling error		=
// ==============================

int		check_arg(char **ar);
int		handling_duplicate(int	*ar, t_stack *s);
int		handling_err(char **arg, t_stack *s);

// ==============================
// =		instraction			=
// ==============================

void	push_a(t_stack *a, t_stack *b, int show);
void	push_b(t_stack *a, t_stack *b, int show);
void	swap_a(t_stack *a, int show);
void	swap_b(t_stack *b, int show);
void	swap_ab(t_stack *a, t_stack *b, int show);
void	retate_a(t_stack *a, t_stack *b, int show);
void	retate_b(t_stack *a, t_stack *b, int show);
void	retate_ab(t_stack *a, t_stack *b, int show);
void	reverse_retate_a(t_stack *a, t_stack *b, int show);
void	reverse_retate_b(t_stack *a, t_stack *b, int show);
void	reverse_retate(t_stack *a, t_stack *b, int show);

// ==============================
// =		implementation		=
// ==============================

void	create_stack(t_stack *p, char **arg);
void	ft_push(int e, t_stack *p);
void	ft_pop(int *e, t_stack	*p);
int		is_empty(t_stack *p);
void	ft_print(t_stack *s);
int		stack_empty(t_stack *p);
int		stack_full(t_stack *p);

// ===============================
// =		sorted stack		 =
// ===============================

void	sort_three(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
void	sort_for_size(t_stack *a, t_stack *b);
int		get_index(t_stack *s, int *array);
void	continue_sort(t_stack *a, t_stack *b);

// ==============================
// =		Utils functions		=
// ==============================

void	free_2d_array(char **ar);
int		fill_array(char **arg, int	*ar, int start);
t_info	find_max(t_stack *s);
t_info	find_min(t_stack *s);
int		*fill_array_sorted_from_stack(t_stack *s);

//===================================
//=		Utils instractioons			=
//===================================

void	fill_arr(t_stack *s);
void	reverse_stack(t_stack *s, t_stack *p);

//=======================================
//=		utils implimenetation stack		=
//=======================================

int		arg_count(char **arg);
void	fill_stack(int *arg, t_stack *s);

#endif
