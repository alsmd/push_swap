/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 23:51:37 by flda-sil          #+#    #+#             */
/*   Updated: 2022/01/14 05:33:03 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_three(t_push_swap *push_swap)
{
	int	first;
	int	second;
	int	third;

	first = push_swap->a->value;
	second = push_swap->a->next->value;
	third = push_swap->a->next->next->value;
	if (first > second && second < third && third > first)
		sa(push_swap);
	else if (first < second && second > third && third < first)
		rra(push_swap);
	else if (first > second && second < third && third < first)
		ra(push_swap);
	else if (first > second && second > third && third < first)
	{
		sa(push_swap);
		rra(push_swap);
	}
	else if (first < second && second > third && third > first)
	{
		rra(push_swap);
		sa(push_swap);
	}
}
