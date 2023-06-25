/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:51:39 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/23 13:26:03 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Function that returns the length of an array of strings
 * 
 * @param args array of strings
 * @return int (length of the array)
 */
static int	arr_length(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

/**
 * @brief Function that create a stack and initialize it with the arguments
 * passed to the program.
 * 
 * @param args array of strings
 * @return t_stack* (pointer to the stack a)
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

/**
 * @brief Function that create a stack b
 * 
 * @return t_stack* (pointer to the stack b)
 */
t_stack	*initialize_stack_b(void)
{
	t_stack	*s_b;

	s_b = malloc(sizeof(t_stack));
	s_b->top = -1;
	s_b->size = 0;
	return (s_b);
}

/**
 * @brief Function that prints the stack passed as an argument
 * (Not used in the program)
 * 
 * @param stack to print
 */
void	print_stack(t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i >= 0)
	{
		ft_printf("numbers[%i]: %i\n", i, stack->numbers[i]);
		i--;
	}
}

bool	stack_sorted(t_stack *stack, char *order)
{
	int	i;

	if (ft_strncmp(order, "des", 3))
	{
		i = stack->top - 1;
		while (i > 0)
		{
			if (stack->numbers[i] > stack->numbers[i + 1])
				return (false);
			i--;
		}
		return (true);
	}
	else if (ft_strncmp(order, "asc", 3))
	{
		i = 1;
		while (i++ < stack->top)
		{
			if (stack->numbers[i] < stack->numbers[i - 1])
				return (false);
		}
		return (true);
	}
	else
		return (false);
}
