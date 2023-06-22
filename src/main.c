/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:25:23 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/22 12:37:06 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief function that checks if the number passed as an argument
 * is repeated.
 * 
 * @param args the array of arguments
 * @param a the position of the argument to check
 * @param nbr the number to check
 * @return true if the number is not repeated
 * @return false if the number is repeated
 */
static bool	ft_isrepeated(char **args, int a, int nbr)
{
	int	i;

	i = 0;
	while (args[i] && i < a)
	{
		if (ft_atoi(args[i]) == nbr)
			return (false);
		i++;
	}
	return (true);
}

/**
 * @brief function that checks if the argument passed to the program
 * is a number.
 * 
 * @param arg the argument to check
 * @return true if the argument is a number
 * @return false if the argument is not a number
 */
static bool	ft_isnumber(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (false);
		i++;
	}
	return (true);
}

/**
 * @brief function that prints the error message and exits the program.
 * 
 */
void	error(void)
{
	ft_printf("Error\n");
	exit(1);
}

/**
 * @brief function that checks the arguments passed to the program
 * and if they are not valid, it calls the error function.
 * 
 * @param args 
 */
static void	check_arguments(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!ft_isnumber(args[i]))
			error();
		else if (!ft_isrepeated(args, i, ft_atoi(args[i])))
			error();
		i++;
	}
}

/**
 * @brief The main function of the program that, after checking
 * if the args are okay, initializes the stacks and
 * calls the sorting functions.
 * 
 * @param ac count of arguments
 * @param av array of arguments
 * @return int return 0 in case of success
 */
int	main(int ac, char **av)
{
	t_stack	*s_a;
	t_stack	*s_b;
	char	**args = NULL;

	if (ac <= 1)
		error();
	else if (ac == 2)
		args = ft_split(av[1], ' ');
	else
		args = av + 1;
	check_arguments(args);
	s_a = initialize_stack_a(args);
	s_b = initialize_stack_b();
	if (s_a->size <= 6)
		smallsort(s_a, s_b);
	/* else
		supersort(s_a, s_b); */
	// print_stack(s_a);
	return (0);
}
