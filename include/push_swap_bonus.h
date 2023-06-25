/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:22:27 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/25 17:31:11 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "push_swap.h"

// checkerswap.c
void	checker_sa(t_stack *s_a);
void	checker_sb(t_stack *s_b);
void	checker_ss(t_stack *s_a, t_stack *s_b);

// checkerrrotate.c
void	checker_rra(t_stack *s_a);
void	checker_rrb(t_stack *s_b);
void	checker_rrr(t_stack *s_a, t_stack *s_b);

// checkerrotate.c
void	checker_ra(t_stack *s_a);
void	checker_rb(t_stack *s_b);
void	checker_rr(t_stack *s_a, t_stack *s_b);

// checkerpush.c
void	checker_pa(t_stack *s_a, t_stack *s_b);
void	checker_pb(t_stack *s_a, t_stack *s_b);

#endif