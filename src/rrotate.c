/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:39:49 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/17 21:20:12 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	r_rotate(t_stack *stack)
{
	int	save;
	int	size;

	save = stack->numbers[stack->top];
	size = stack->top;
	while (size > 0)
	{
		stack->numbers[size] = stack->numbers[size - 1];
		size--;
	}
	stack->numbers[0] = save;
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

void	rrs(t_stack *s_a, t_stack *s_b)
{
	r_rotate(s_a);
	r_rotate(s_b);
	ft_printf("rrs\n");
}
