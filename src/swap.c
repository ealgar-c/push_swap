/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:39:49 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/19 16:01:07 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_stack *stack)
{
	int	save;

	save = stack->numbers[stack->top];
	stack->numbers[stack->top] = stack->numbers[stack->top - 1];
	stack->numbers[stack->top - 1] = save;
}

void	sa(t_stack *s_a)
{
	swap(s_a);
	ft_printf("sa\n");
}

void	sb(t_stack *s_b)
{
	swap(s_b);
	ft_printf("sb\n");
}

void	ss(t_stack *s_a, t_stack *s_b)
{
	swap(s_a);
	swap(s_b);
	ft_printf("ss\n");
}
