/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:39:49 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/17 21:20:03 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push(t_stack *s_orig, t_stack *s_dest)
{
	int	i;

	s_dest->top++;
	i = s_dest->top;
	while (i > 0)
	{
		s_dest->numbers[i] = s_dest->numbers[i - 1];
		i--;
	}
	s_dest->numbers[0] = s_orig->numbers[0];
	i = 0;
	while (i < s_orig->top)
	{
		s_orig->numbers[i] = s_orig->numbers[i + 1];
		i++;
	}
	s_orig->top--;
}

void	pa(t_stack *s_a, t_stack *s_b)
{
	push(s_b, s_a);
	ft_printf("rra\n");
}

void	pb(t_stack *s_a, t_stack *s_b)
{
	push(s_a, s_b);
	ft_printf("rrb\n");
}
