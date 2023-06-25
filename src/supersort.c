/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supersort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:24:51 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/23 13:24:01 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	min_position(t_stack *s_a)
{
	int	i;
	int	aux;

	i = s_a->top - 1;
	aux = s_a->top;
	while (i >= 0)
	{
		if (s_a->numbers[i] < s_a->numbers[aux])
			aux = i;
		i--;
	}
	return (aux);
}

static int	max_position(t_stack *s_a)
{
	int	i;
	int	aux;

	i = s_a->top - 1;
	aux = s_a->top;
	while (i >= 0)
	{
		if (s_a->numbers[i] > s_a->numbers[aux])
			aux = i;
		i--;
	}
	return (aux);
}

static int	get_max_nbr_pos(t_stack *s_b)
{
	int	i;
	int	aux;

	i = s_b->top - 1;
	aux = s_b->top;
	while (i >= 0)
	{
		if (s_b->numbers[i] > s_b->numbers[aux])
			aux = i;
		i--;
	}
	return (aux);
}

static void	nbrstoa(t_stack *s_a, t_stack *s_b)
{
	int	top_back;

	while (s_b->top >= 0)
	{
		top_back = get_max_nbr_pos(s_b);
		if (top_back > s_b->top / 2)
		{
			while (top_back < s_b->top)
			{
				rb(s_b);
				top_back++;
			}
		}
		else
		{
			while (top_back >= 0)
			{
				rrb(s_b);
				top_back--;
			}
		}
		pa(s_a, s_b);
	}
}

void	supersort(t_stack *s_a, t_stack *s_b)
{
	int	chunk_nbr;
	int	chunk_size;
	int	chunk_start;
	int	chunk_end;

	if (s_a->size <= 100)
		chunk_nbr = 5;
	else
		chunk_nbr = 11;
	chunk_size = s_a->numbers[max_position(s_a)] / chunk_nbr;
	chunk_start = s_a->numbers[min_position(s_a)];
	while (chunk_start < s_a->numbers[max_position(s_a)])
	{
		chunk_end = chunk_start + chunk_size;
		chunksrt(s_a, s_b, chunk_start, chunk_end);
		chunk_start += chunk_size;
	}
	nbrstoa(s_a, s_b);
}
