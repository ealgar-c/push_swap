/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:25:23 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/06 19:17:37 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_to_stack(t_list **stack_a, char **args)
{
	int		i;
	t_list	*new;

	i = 1;
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack_a, new);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	*actual;
	int		i;
	
	//t_list	**stack_b;
	stack_a = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	(void)argc;
	get_to_stack(stack_a, argv);
	ft_printf("tamaño del stack a: %i\n", ft_lstsize(*stack_a));
	i = 1;
	actual = *stack_a;
	while (actual->next)
	{
		ft_printf("%i\n", actual->content);
		actual = actual->next;
	}
	return (0);
}
