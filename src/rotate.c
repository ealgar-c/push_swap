/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:39:49 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/17 21:20:08 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate(t_stack *stack)
{
	int	save;
	int	i;

	i = 0;
	save = stack->numbers[0];
	while (i < stack->top)
	{
		stack->numbers[i] = stack->numbers[i + 1];
		i++;
	}
	stack->numbers[stack->top] = save;
}

void	ra(t_stack *s_a)
{
	rotate(s_a);
	ft_printf("rra\n");
}

void	rb(t_stack *s_b)
{
	rotate(s_b);
	ft_printf("rrb\n");
}

void	rs(t_stack *s_a, t_stack *s_b)
{
	rotate(s_a);
	rotate(s_b);
	ft_printf("rrs\n");
}