/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:39:49 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/22 13:21:56 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	ra(t_stack *s_a)
{
	rotate(s_a);
	ft_printf("ra\n");
}

void	rb(t_stack *s_b)
{
	rotate(s_b);
	ft_printf("rb\n");
}

void	rr(t_stack *s_a, t_stack *s_b)
{
	rotate(s_a);
	rotate(s_b);
	ft_printf("rs\n");
}
