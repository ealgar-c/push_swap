/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argumentscheck.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:52:17 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/25 17:53:33 by ealgar-c         ###   ########.fr       */
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
 * @brief function that checks the arguments passed to the program
 * and if they are not valid, it calls the error function.
 * 
 * @param args 
 */
void	check_arguments(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!ft_isnumber(args[i]))
			exit_with_errors();
		else if (!ft_isrepeated(args, i, ft_atoi(args[i])))
			exit_with_errors();
		else if (ft_atoi(args[i]) > __INT_MAX__)
			exit_with_errors();
		i++;
	}
}
