/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_aux_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:14:19 by flda-sil          #+#    #+#             */
/*   Updated: 2022/01/14 05:31:28 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	more_than_one_chunk(t_push_swap *push_swap, t_stack *stack)
{
	while (stack)
	{
		if (stack->id != push_swap->active_id)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int	chunk_in_last(t_push_swap *push_swap, t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	if (stack->id == push_swap->active_id)
		return (1);
	return (0);
}

void	bring_chunk_up(t_push_swap *push_swap, char stack)
{
	if (more_than_one_chunk(push_swap, get_stack(push_swap, stack)))
	{
		while (chunk_in_last(push_swap, get_stack(push_swap, stack)))
			rotate_stack_down(push_swap, stack);
	}
}

int	is_sorted(t_push_swap *push_swap)
{
	t_stack	*a;

	a = push_swap->a;
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}
