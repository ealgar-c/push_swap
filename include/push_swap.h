/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:26:51 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/25 17:49:48 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdbool.h>
# include <unistd.h>

typedef struct s_stack
{
	int	numbers[1024];
	int	top;
	int	size;
}	t_stack;

// main.c
void	exit_with_errors(void);

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
void	exit_without_errors(t_stack *s_a, t_stack *s_b);
void	check_arguments(char **args);

// supersort.c
void	supersort(t_stack *s_a, t_stack *s_b);

// chunksort.c
void	chunksrt(t_stack *s_a, t_stack *s_b, int chunk_start, int chunk_end);
#endif