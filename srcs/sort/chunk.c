/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:28:31 by flda-sil          #+#    #+#             */
/*   Updated: 2022/01/14 05:31:58 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push_lower_chunk(t_push_swap *push_swap, char from, char to)
{
	int		direction;
	int		size;
	t_stack	*stack;

	stack = get_stack(push_swap, from);
	set_array(push_swap, stack);
	sort_array(push_swap->array, push_swap->array_size);
	size = push_swap->mid_point;
	push_swap->next_id += 1;
	while (size--)
	{
		direction = get_direction(push_swap, stack);
		push_to(push_swap, stack, to, direction);
		stack = get_stack(push_swap, from);
	}
	free(push_swap->array);
}

void	change_array(t_push_swap *push_swap)
{
	int		new_mid_point;
	int		*new_array;
	int		size;

	size = push_swap->array_size - push_swap->mid_point;
	new_mid_point = size;
	new_array = (int *) ft_calloc(1, sizeof(int) * size);
	while (size)
	{
		size--;
		new_array[size] = push_swap->array[push_swap->mid_point + size];
	}
	free(push_swap->array);
	push_swap->array = new_array;
	push_swap->mid_point = new_mid_point;
}

void	push_higher_chunk(t_push_swap *push_swap, char from, char to)
{
	int		direction;
	int		size;
	t_stack	*stack;

	stack = get_stack(push_swap, from);
	set_array(push_swap, stack);
	sort_array(push_swap->array, push_swap->array_size);
	change_array(push_swap);
	size = push_swap->mid_point;
	push_swap->next_id += 1;
	while (size--)
	{
		direction = get_direction(push_swap, stack);
		push_to(push_swap, stack, to, direction);
		stack = get_stack(push_swap, from);
	}
	free(push_swap->array);
}
