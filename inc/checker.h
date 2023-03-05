/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:17:28 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/03/04 10:20:02 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <fcntl.h>
# include "../gnl/get_next_line.h"
# include "push_swap.h"

void	comparision(char *ptr, char *str, int *ret, int i);
int		get_instraction(char *ptr, t_stack *a, t_stack *b);
int		handling_checker(t_stack *a, t_stack *b);

#endif
