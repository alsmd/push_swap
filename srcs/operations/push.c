/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:11:53 by flda-sil          #+#    #+#             */
/*   Updated: 2022/01/14 15:09:57 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	pa(t_push_swap *push_swap)
{
	t_stack	*b_second;
	t_stack	*a_first;

	if (push_swap->b)
	{
		b_second = push_swap->b->next;
		a_first = push_swap->a;
		push_swap->a = push_swap->b;
		push_swap->a->next = a_first;
		if (a_first)
			a_first->before = push_swap->a;
		push_swap->b = b_second;
		if (push_swap->b)
			push_swap->b->before = 0;
		if (push_swap->mode != CHECKER)
			write(1, "pa\n", 3);
	}
}

void	pb(t_push_swap *push_swap)
{
	t_stack	*a_second;
	t_stack	*b_first;

	if (push_swap->a)
	{
		a_second = push_swap->a->next;
		b_first = push_swap->b;
		push_swap->b = push_swap->a;
		push_swap->b->next = b_first;
		if (b_first)
			b_first->before = push_swap->b;
		push_swap->a = a_second;
		if (a_second)
			a_second->before = 0;
		if (push_swap->mode != CHECKER)
			write(1, "pb\n", 3);
	}
}
