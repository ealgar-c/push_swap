/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supersort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:24:51 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/28 12:39:39 by ealgar-c         ###   ########.fr       */
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

static int	max_position(t_stack *stack)
{
	int	i;
	int	aux;

	i = stack->top - 1;
	aux = stack->top;
	while (i >= 0)
	{
		if (stack->numbers[i] > stack->numbers[aux])
			aux = i;
		i--;
	}
	return (aux);
}

/**
 * @brief once the stack a is sorted in chunks, this function
 * takes the numbers from the stack b and puts them in the stack a
 * in the most efficient way.
 * 
 * @param s_a 
 * @param s_b 
 */
static void	nbrstoa(t_stack *s_a, t_stack *s_b)
{
	int	top_back;

	while (s_b->top >= 0)
	{
		top_back = max_position(s_b);
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

/**
 * @brief Funciton that choose the best numebr of chunks depending on
 * the amount of numbers in the stack a and sort each chunk.
 * 
 * For it, it takes the posotion of min and the max number of the stack a and 
 * send each chunk to the function chunksrt.
 * 
 * @param s_a 
 * @param s_b 
 */
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
