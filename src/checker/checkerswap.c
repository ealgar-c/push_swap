/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:39:49 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/25 17:45:04 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

static void	swap(t_stack *stack)
{
	int	save;

	save = stack->numbers[stack->top];
	stack->numbers[stack->top] = stack->numbers[stack->top - 1];
	stack->numbers[stack->top - 1] = save;
}

void	checker_sa(t_stack *s_a)
{
	swap(s_a);
}

void	checker_sb(t_stack *s_b)
{
	swap(s_b);
}

void	checker_ss(t_stack *s_a, t_stack *s_b)
{
	swap(s_a);
	swap(s_b);
}
