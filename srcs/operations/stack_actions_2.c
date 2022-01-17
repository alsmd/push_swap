/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:32:12 by flda-sil          #+#    #+#             */
/*   Updated: 2022/01/14 05:27:14 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push_to_stack(t_push_swap *push_swap, char stack)
{
	if (stack == A)
		pa(push_swap);
	else if (stack == B)
		pb(push_swap);
}

void	rotate_stack_up(t_push_swap *push_swap, char stack)
{
	if (stack == A)
		ra(push_swap);
	else if (stack == B)
		rb(push_swap);
}

void	swap_stack(t_push_swap *push_swap, char stack)
{
	if (stack == A)
		sa(push_swap);
	else if (stack == B)
		sb(push_swap);
}

void	rotate_stack_down(t_push_swap *push_swap, char stack)
{
	if (stack == A)
		rra(push_swap);
	else if (stack == B)
		rrb(push_swap);
}

t_stack	*get_stack(t_push_swap *push_swap, char stack)
{
	if (stack == A)
		return (push_swap->a);
	else
		return (push_swap->b);
}
