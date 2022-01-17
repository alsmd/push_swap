/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:32:12 by flda-sil          #+#    #+#             */
/*   Updated: 2022/01/12 19:35:10 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	add_to_stack(t_push_swap *push_swap, int value)
{
	t_stack	*new_value;
	t_stack	*begin;

	new_value = (t_stack *) ft_calloc(1, sizeof(t_stack));
	new_value->value = value;
	begin = push_swap->a;
	if (push_swap->a == 0)
	{
		push_swap->a = new_value;
		return ;
	}
	while (begin->next)
		begin = begin->next;
	new_value->before = begin;
	begin->next = new_value;
}

int	is_in_stack(t_push_swap *push_swap, int value)
{
	t_stack	*begin;

	begin = push_swap->a;
	while (begin)
	{
		if (begin->value == value)
			return (1);
		begin = begin->next;
	}
	return (0);
}
