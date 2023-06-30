/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:38:37 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/28 12:32:22 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Function that sorts 3 numbers in a stack in less
 * than 3 movements.
 * 
 * @param s_a (stack a)
 */
void	sort3(t_stack *s_a)
{
	int	*nums;

	nums = s_a->numbers;
	if (nums[2] > nums[1] && nums[1] > nums[0] && nums[0] < nums[2])
	{
		sa(s_a);
		rra(s_a);
	}
	else if (nums[2] > nums[1] && nums[1] < nums[0] && nums[0] < nums[2])
		ra(s_a);
	else if (nums[0] > nums[1] && nums[1] < nums[2] && nums[0] > nums[2])
		sa(s_a);
	else if (nums[0] > nums[2] && nums[2] < nums[1] && nums[0] < nums[1])
	{
		sa(s_a);
		ra(s_a);
	}
	else if (nums[0] < nums[2] && nums[2] < nums[1] && nums[1] > nums[0])
		rra(s_a);
}

/**
 * @brief Function that takes the smallest number of the stack a
 * and puts it on the stack b.
 * 
 * @param s_a (stack a)
 * @param s_b (stack b)
 */
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

/**
 * @brief Best way to sort 5 numbers in a stack in less
 * than 12 movements.
 * 
 * @param s_a (stack a)
 * @param s_b (stack b)
 */
void	sort5(t_stack *s_a, t_stack *s_b)
{
	smallest_tob(s_a, s_b);
	smallest_tob(s_a, s_b);
	sort3(s_a);
	pa(s_a, s_b);
	pa(s_a, s_b);
}

/**
 * @brief Function that takes the cases to sort stacks of
 * less than 6 numbers. In case of the number of numbers
 * we have it does something different.
 * 
 * @param s_a (stack a)
 * @param s_b (stack b)
 */
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
