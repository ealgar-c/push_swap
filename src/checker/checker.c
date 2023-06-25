/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:18:28 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/25 18:05:19 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

void	check_instruction(char *inst, t_stack *s_a, t_stack *s_b)
{
	if (!ft_strncmp(inst, "sa\n", 3))
		checker_sa(s_a);
	else if (!ft_strncmp(inst, "sb\n", 3))
		checker_sb(s_b);
	else if (!ft_strncmp(inst, "ra\n", 3))
		checker_ra(s_a);
	else if (!ft_strncmp(inst, "rb\n", 3))
		checker_rb(s_b);
	else if (!ft_strncmp(inst, "rr\n", 3))
		checker_rr(s_a, s_b);
	else if (!ft_strncmp(inst, "rra\n", 3))
		checker_rra(s_a);
	else if (!ft_strncmp(inst, "rrb\n", 3))
		checker_rrb(s_b);
	else if (!ft_strncmp(inst, "rrr\n", 3))
		checker_rrr(s_a, s_b);
	else if (!ft_strncmp(inst, "pa\n", 3))
		checker_pa(s_a, s_b);
	else if (!ft_strncmp(inst, "pb\n", 3))
		checker_pb(s_a, s_b);
	else
		free(inst);
}

void	check_program(t_stack *s_a, t_stack *s_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		check_instruction(line, s_a, s_b);
		line = get_next_line(0);
	}
}

bool	check_sorting(t_stack *s_a)
{
	int	i;

	i = s_a->top;
	while (i >= 0)
	{
		if (i == 0)
			break ;
		if (s_a->numbers[i] > s_a->numbers[i - 1])
			return (false);
		i--;
	}
	return (true);
}

int	main(int ac, char **av)
{
	t_stack	*s_a;
	t_stack	*s_b;
	char	**args;

	if (ac <= 1)
	{
		args = NULL;
		exit_with_errors();
	}
	else if (ac == 2)
		args = ft_split(av[1], ' ');
	else
		args = av + 1;
	check_arguments(args);
	s_a = initialize_stack_a(args);
	s_b = initialize_stack_b();
	check_program(s_a, s_b);
	if (check_sorting(s_a) && s_b->top < 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	exit_without_errors(s_a, s_b);
	return (0);
}
