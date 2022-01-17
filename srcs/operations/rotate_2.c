/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:11:53 by flda-sil          #+#    #+#             */
/*   Updated: 2022/01/14 15:10:15 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rr(t_push_swap *push_swap)
{
	push_swap->double_action = 1;
	ra(push_swap);
	rb(push_swap);
	push_swap->double_action = 0;
	if (push_swap->mode != CHECKER)
		write(1, "rr\n", 3);
}

void	rrr(t_push_swap *push_swap)
{
	push_swap->double_action = 1;
	rra(push_swap);
	rrb(push_swap);
	push_swap->double_action = 0;
	if (push_swap->mode != CHECKER)
		write(1, "rrr\n", 4);
}
