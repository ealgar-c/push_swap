/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supersort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:24:51 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/20 11:35:30 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	chunksrt(t_stack *s_a, t_stack *s_b, int chunk_start, int chunk_end)
{
	
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
