/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:25:23 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/17 21:34:32 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief We are going to use this function to get all the numbers to the stack A,
 * 			for that, we need a pointer to the stack and the arguments.
 * 			(IN THIS VERSION WE CAN ONLY SEND NUMBERS IN SEPARATED ARGUMENTS)
 * 		(THIS IS NOT THE FINAL VERSION OF THE FUNCTION, MOSTLY BECAUSE THE 
 * 		NUMBER OF NUMBERS WE ARE GOING TO HAVE IN THE STACKS IS NOT ALWAYS
 * 		THE SAME)
 * 
 * @param argc 
 * @param argv 
 * @param s_a 
 */
/* void	get_to_stack(int argc, char **argv, t_stack *s_a)
{
	int	i;

	i = 1;
	s_a->numbers = malloc((argc - 1) * sizeof(int));
	while (i < argc)
	{
		s_a->numbers[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	s_a->size = argc - 2;
} */

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

void	initialize_stack_a(t_stack *s_a, char **args)
{
	s_a = malloc(sizeof(t_stack));
	s_a->top = 0;
	ft_printf("%i\n", arr_length(args));
	while (s_a->top < arr_length(args))
	{
		s_a->numbers[s_a->top] = ft_atoi(args[s_a->top]);
		s_a->top++;
	}
	ft_printf("%i\n", s_a->top);
	// pause ();
}

void	initialize_stack_b(t_stack *s_b)
{
	s_b = malloc(sizeof(t_stack));
	s_b->top = 0;
}

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (i <= stack->top)
	{
		ft_printf("numero %i: %i\n", i, stack->numbers[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	s_a;
	t_stack	s_b;
	char	**args;

	if (ac <= 1)
		return (0);
	else if (ac == 2)
		args = ft_split(av[1], ' ');
	else
		args = av + 1;
	initialize_stack_a(&s_a, args);
	ft_printf("El top del stack a se encuentra en: %i\n", s_a.top);
	initialize_stack_b(&s_b);
	pause();
	print_stack(&s_a);
	sa(&s_a);
	print_stack(&s_a);
	rra(&s_a);
	print_stack(&s_a);
	ra(&s_a);
	print_stack(&s_a);
	pause ();
	pb(&s_a, &s_b);
	ft_printf("El stack a es: \n");
	print_stack(&s_a);
	ft_printf("El stack b es: \n");
	print_stack(&s_b);
	return (0);
}
