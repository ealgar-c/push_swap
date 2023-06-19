/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:26:51 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/19 18:15:43 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdbool.h>

typedef struct s_stack
{
	int	numbers[1024];
	int	top;
	int	size;
}	t_stack;

// swap.c
void	sa(t_stack *s_a);
void	sb(t_stack *s_b);
void	ss(t_stack *s_a, t_stack *s_b);

// rrotate.c
void	rra(t_stack *s_a);
void	rrb(t_stack *s_b);
void	rrr(t_stack *s_a, t_stack *s_b);

// rotate.c
void	ra(t_stack *s_a);
void	rb(t_stack *s_b);
void	rr(t_stack *s_a, t_stack *s_b);

// push.c
void	pa(t_stack *s_a, t_stack *s_b);
void	pb(t_stack *s_a, t_stack *s_b);
void	push(t_stack *src, t_stack *dst);

// smallsort.c
void	smallsort(t_stack *s_a, t_stack *s_b);

// stack_management.c
t_stack	*initialize_stack_a(char **args);
t_stack	*initialize_stack_b(void);
void	print_stack(t_stack *stack);

#endif