/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:11:48 by flda-sil          #+#    #+#             */
/*   Updated: 2022/01/14 15:11:58 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sa(t_push_swap *push_swap)
{
	t_stack	*third;
	t_stack	*first;
	int		has_two_elements;

	has_two_elements = (push_swap->a != 0 && push_swap->a->next != 0);
	if (has_two_elements)
	{
		first = push_swap->a;
		third = push_swap->a->next->next;
		push_swap->a = push_swap->a->next;
		push_swap->a->before = 0;
		push_swap->a->next = first;
		first->next = third;
		first->before = push_swap->a;
		if (third)
			third->before = first;
		if (push_swap->double_action == 0 && push_swap->mode != CHECKER)
			write(1, "sa\n", 3);
	}
}

void	sb(t_push_swap *push_swap)
{
	t_stack	*third;
	t_stack	*first;
	int		has_two_elements;

	has_two_elements = (push_swap->b != 0 && push_swap->b->next != 0);
	if (has_two_elements)
	{
		first = push_swap->b;
		third = push_swap->b->next->next;
		push_swap->b = push_swap->b->next;
		push_swap->b->next = first;
		first->before = push_swap->b;
		first->next = third;
		if (third)
			third->before = first;
		if (push_swap->double_action == 0 && push_swap->mode != CHECKER)
			write(1, "sb\n", 3);
	}
}

void	ss(t_push_swap *push_swap)
{
	push_swap->double_action = 1;
	sa(push_swap);
	sb(push_swap);
	push_swap->double_action = 0;
	if (push_swap->mode != CHECKER)
		write(1, "ss\n", 3);
}
