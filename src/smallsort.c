/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:38:37 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/19 18:10:22 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort3(t_stack *s_a)
{
	if (s_a->numbers[2] > s_a->numbers[1] && s_a->numbers[1] < s_a->numbers[0]
		&& s_a->numbers[0] > s_a->numbers[2])
		sa(s_a);
	else if (s_a->numbers[2] > s_a->numbers[1]
		&& s_a->numbers[1] > s_a->numbers[0]
		&& s_a->numbers[0] < s_a->numbers[2])
	{
		sa(s_a);
		rra(s_a);
	}
	else if (s_a->numbers[2] > s_a->numbers[1]
		&& s_a->numbers[1] < s_a->numbers[0]
		&& s_a->numbers[0] < s_a->numbers[2])
		ra(s_a);
	else if (s_a->numbers[2] > s_a->numbers[1]
		&& s_a->numbers[1] > s_a->numbers[0]
		&& s_a->numbers[0] < s_a->numbers[2])
	{
		sa(s_a);
		ra(s_a);
	}
	else if (s_a->numbers[2] > s_a->numbers[1]
		&& s_a->numbers[1] > s_a->numbers[0]
		&& s_a->numbers[0] < s_a->numbers[2])
		rra(s_a);
}

void	smallest_tob(t_stack *s_a, t_stack *s_b)
{
	int	i;
	int	aux_pos;

	i = s_a->top - 1;
	aux_pos = s_a->top;
	while (i >= 0)
	{
		if (s_a->numbers[i] < s_a->numbers[aux_pos])
			aux_pos = i;
		i--;
	}
	while (aux_pos < s_a->top)
	{
		ra(s_a);
		aux_pos++;
	}
	pb(s_a, s_b);
}

void	sort5(t_stack *s_a, t_stack *s_b)
{
	int	i;

	i = 0;
	smallest_tob(s_a, s_b);
	smallest_tob(s_a, s_b);
	sort3(s_a);
	pa(s_a, s_b);
	pa(s_a, s_b);
}

void	smallsort(t_stack *s_a, t_stack *s_b)
{
	if (s_a->size == 2)
	{
		if (s_a->numbers[s_a->top] > s_a->numbers[s_a->top - 1])
			sa(s_a);
	}
	else if (s_a->size == 3)
		sort3(s_a);
	else if (s_a->size == 4)
	{
		smallest_tob(s_a, s_b);
		sort3(s_a);
		pa(s_a, s_b);
	}
	else if (s_a->size == 5)
		sort5(s_a, s_b);
	else
	{
		smallest_tob(s_a, s_b);
		sort5(s_a, s_b);
		pa(s_a, s_b);
	}
}
