/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:39:49 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/25 17:44:57 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

void	push(t_stack *src, t_stack *dst)
{
	dst->top++;
	dst->numbers[dst->top] = src->numbers[src->top];
	src->top--;
}

void	checker_pa(t_stack *s_a, t_stack *s_b)
{
	push(s_b, s_a);
}

void	checker_pb(t_stack *s_a, t_stack *s_b)
{
	push(s_a, s_b);
}
