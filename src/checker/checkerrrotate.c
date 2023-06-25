/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerrrotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:39:49 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/25 17:45:01 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

static void	r_rotate(t_stack *stack)
{
	int	save;
	int	i;

	save = stack->numbers[0];
	i = 0;
	while (i < stack->top)
	{
		stack->numbers[i] = stack->numbers[i + 1];
		i++;
	}
	stack->numbers[stack->top] = save;
}

void	checker_rra(t_stack *s_a)
{
	r_rotate(s_a);
}

void	checker_rrb(t_stack *s_b)
{
	r_rotate(s_b);
}

void	checker_rrr(t_stack *s_a, t_stack *s_b)
{
	r_rotate(s_a);
	r_rotate(s_b);
}
