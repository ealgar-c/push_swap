/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:25:23 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/19 18:24:39 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	error(void)
{
	ft_printf("Error\n");
	exit(1);
}

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

int	main(int ac, char **av)
{
	t_stack	*s_a;
	t_stack	*s_b;
	char	**args;

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
	else
		supersort(s_a, s_b);
	print_stack(s_a);
	return (0);
}
