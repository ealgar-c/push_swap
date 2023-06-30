/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:51:39 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/30 13:46:31 by ealgar-c         ###   ########.fr       */
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

/* void	ft_leakss(void)
{
	system("leaks -q push_swap");
	atexit(ft_leakss);
} */

void	exit_without_errors(int ac, char **args, t_stack *s_a, t_stack *s_b)
{
	char	**ptr;

	if (ac == 2)
	{
		ptr = args;
		while (*ptr)
		{
			free(*ptr);
			ptr++;
		}
		free(args);
	}
	free(s_a);
	free(s_b);
	exit(0);
}

/**
 * @brief function that prints the error message and exits the program.
 * 
 */
void	exit_with_errors(int ac, char **args)
{
	char	**ptr;

	if (ac == 2)
	{
		ptr = args;
		while (*ptr)
		{
			free(*ptr);
			ptr++;
		}
		free(args);
	}
	ft_printf("Error\n");
	exit(1);
}
