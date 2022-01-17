/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:11:53 by flda-sil          #+#    #+#             */
/*   Updated: 2022/01/14 15:16:08 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ra(t_push_swap *push_swap)
{
	t_stack	*bottom_element;

	bottom_element = push_swap->a;
	if (bottom_element && bottom_element->next)
	{
		while (bottom_element && bottom_element->next)
			bottom_element = bottom_element->next;
		bottom_element->next = push_swap->a;
		push_swap->a = push_swap->a->next;
		push_swap->a->before = 0;
		bottom_element->next->next = 0;
		bottom_element->next->before = bottom_element;
		if (push_swap->double_action == 0 && push_swap->mode != CHECKER)
			write(1, "ra\n", 3);
	}
}

void	rra(t_push_swap *push_swap)
{
	t_stack	*penult_element;
	t_stack	*bottom_element;

	penult_element = push_swap->a;
	if (penult_element && penult_element->next)
	{
		while (penult_element && penult_element->next->next)
			penult_element = penult_element->next;
		bottom_element = penult_element->next;
		bottom_element->before = 0;
		penult_element->next = 0;
		bottom_element->next = push_swap->a;
		push_swap->a->before = bottom_element;
		push_swap->a = bottom_element;
		if (push_swap->double_action == 0 && push_swap->mode != CHECKER)
			write(1, "rra\n", 4);
	}
}

void	rb(t_push_swap *push_swap)
{
	t_stack	*bottom_element;

	bottom_element = push_swap->b;
	if (bottom_element && bottom_element->next)
	{
		while (bottom_element && bottom_element->next)
			bottom_element = bottom_element->next;
		bottom_element->next = push_swap->b;
		push_swap->b->before = bottom_element;
		push_swap->b = push_swap->b->next;
		push_swap->b->before = 0;
		bottom_element->next->next = 0;
		if (push_swap->double_action == 0 && push_swap->mode != CHECKER)
			write(1, "rb\n", 3);
	}
}

void	rrb(t_push_swap *push_swap)
{
	t_stack	*penult_element;
	t_stack	*bottom_element;

	penult_element = push_swap->b;
	if (penult_element && penult_element->next)
	{
		while (penult_element && penult_element->next->next)
			penult_element = penult_element->next;
		bottom_element = penult_element->next;
		penult_element->next = 0;
		bottom_element->before = 0;
		bottom_element->next = push_swap->b;
		push_swap->b->before = bottom_element;
		push_swap->b = bottom_element;
		if (push_swap->double_action == 0 && push_swap->mode != CHECKER)
			write(1, "rrb\n", 4);
	}
}
