/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:25:23 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/30 13:35:33 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	char	**args;

	if (ac <= 1)
	{
		args = NULL;
		return (0);
	}
	else if (ac == 2)
		args = ft_split(av[1], ' ');
	else
		args = av + 1;
	check_arguments(ac, args);
	s_a = initialize_stack_a(args);
	s_b = initialize_stack_b();
	if (s_a->size <= 6)
		smallsort(s_a, s_b);
	else
		supersort(s_a, s_b);
	exit_without_errors(ac, args, s_a, s_b);
	return (0);
}
