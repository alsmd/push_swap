/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:30:27 by flda-sil          #+#    #+#             */
/*   Updated: 2022/01/14 05:32:24 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	sort_b(t_push_swap *push_swap)
{
	t_stack	*higher;
	t_stack	*b;

	b = push_swap->b;
	higher = b;
	while (b)
	{
		if (b->value > higher->value)
			higher = b;
		b = b->next;
	}
	push_swap->active_id = higher->id;
	push_higher_chunk(push_swap, B, A);
	sort(push_swap);
}

static void	sort_two(t_push_swap *push_swap)
{
	if (push_swap->a->value > push_swap->a->next->value)
	{
		if (push_swap->b && push_swap->b->next && \
			push_swap->b->value < push_swap->b->next->value)
			ss(push_swap);
		else
			sa(push_swap);
	}
}

void	sort(t_push_swap *push_swap)
{
	push_swap->active_id = push_swap->a->id;
	while (get_chunk_size(push_swap, push_swap->a) > 2 && !is_sorted(push_swap))
	{
		if (get_chunk_size(push_swap, push_swap->a) == 3)
		{
			if (push_swap->a->next->next->value > push_swap->a->next->value \
				&& push_swap->a->value > push_swap->a->next->value \
				&& push_swap->a->next->next->value > push_swap->a->value)
			{
				sa(push_swap);
				sort(push_swap);
				return ;
			}
		}
		push_lower_chunk(push_swap, A, B);
	}
	bring_chunk_up(push_swap, A);
	if (get_chunk_size(push_swap, push_swap->a) == 2)
		sort_two(push_swap);
	if (push_swap->b)
		sort_b(push_swap);
}
