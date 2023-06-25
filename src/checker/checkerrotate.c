/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:39:49 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/25 17:44:58 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

static void	rotate(t_stack *stack)
{
	int	save;
	int	i;

	save = stack->numbers[stack->top];
	i = stack->top;
	while (i > 0)
	{
		stack->numbers[i] = stack->numbers[i - 1];
		i--;
	}
	stack->numbers[0] = save;
}

void	checker_ra(t_stack *s_a)
{
	rotate(s_a);
}

void	checker_rb(t_stack *s_b)
{
	rotate(s_b);
}

void	checker_rr(t_stack *s_a, t_stack *s_b)
{
	rotate(s_a);
	rotate(s_b);
}
