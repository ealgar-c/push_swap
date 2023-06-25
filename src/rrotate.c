/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:39:49 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/23 13:25:38 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	rra(t_stack *s_a)
{
	r_rotate(s_a);
	ft_printf("rra\n");
}

void	rrb(t_stack *s_b)
{
	r_rotate(s_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *s_a, t_stack *s_b)
{
	r_rotate(s_a);
	r_rotate(s_b);
	ft_printf("rrs\n");
}
