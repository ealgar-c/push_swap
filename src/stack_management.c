/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:51:39 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/19 16:18:43 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	arr_length(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

/**
 * @brief This is an updated version of the function @get_to_stack
 * 		In this version, we dont allocate mamory only for the size of
 * 		the arguments, we allocate a lot of memory so we dont have problems
 * 
 * @param s_a 
 * @param args 
 * @param argc 
 */
t_stack	*initialize_stack_a(char **args)
{
	t_stack	*s_a;
	int		i;

	s_a = malloc(sizeof(t_stack));
	s_a->top = -1;
	s_a->size = arr_length(args);
	i = s_a->size - 1;
	while (i >= 0)
	{
		s_a->top++;
		s_a->numbers[s_a->top] = ft_atoi(args[i]);
		i--;
	}
	return (s_a);
}

t_stack	*initialize_stack_b(void)
{
	t_stack	*s_b;

	s_b = malloc(sizeof(t_stack));
	s_b->top = -1;
	s_b->size = 0;
	return (s_b);
}

void	print_stack(t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i >= 0)
	{
		ft_printf("numero %i: %i\n", i, stack->numbers[i]);
		i--;
	}
}
