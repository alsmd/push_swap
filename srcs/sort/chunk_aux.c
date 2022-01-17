/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:14:19 by flda-sil          #+#    #+#             */
/*   Updated: 2022/01/14 05:31:48 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	get_chunk_size(t_push_swap *push_swap, t_stack *from)
{
	int	size;

	size = 0;
	while (from)
	{
		if (from->id == push_swap->active_id)
			size++;
		from = from->next;
	}
	return (size);
}

void	set_array(t_push_swap *push_swap, t_stack *stack)
{
	int	*array;
	int	size;

	size = get_chunk_size(push_swap, stack);
	push_swap->array_size = size;
	push_swap->mid_point = size / 2;
	array = ft_calloc(1, sizeof(int) * size);
	while (stack)
	{
		if (stack->id == push_swap->active_id)
		{
			size--;
			array[size] = stack->value;
		}
		stack = stack->next;
	}
	push_swap->array = array;
}

void	sort_array(int *tab, int size)
{
	int	holder;
	int	indice1;
	int	indice2;

	indice1 = 0;
	indice2 = 1;
	while (indice1 < size)
	{
		while (indice2 < size)
		{
			if (tab[indice1] > tab[indice2])
			{
				holder = tab[indice2];
				tab[indice2] = tab[indice1];
				tab[indice1] = holder;
			}
			indice2++;
		}
		indice1++;
		indice2 = indice1 + 1;
	}
}

int	get_direction(t_push_swap *push_swap, t_stack *stack)
{
	int	up;
	int	down;

	up = 0;
	down = 1;
	while (stack)
	{
		if (is_in(push_swap->array, stack->value, push_swap->mid_point))
			break ;
		up++;
		stack = stack->next;
	}
	while (stack->next)
		stack = stack->next;
	while (stack)
	{
		if (is_in(push_swap->array, stack->value, push_swap->mid_point))
			break ;
		down++;
		stack = stack->before;
	}
	if (up < down)
		return (E_ROTATE_UP);
	return (E_ROTATE_DOWN);
}

void	push_to(t_push_swap *push_swap, t_stack *from, char to, int direction)
{
	while (TRUE)
	{
		if (is_in(push_swap->array, from->value, push_swap->mid_point))
		{
			from->id = push_swap->next_id;
			push_to_stack(push_swap, to);
			return ;
		}
		if (direction == E_ROTATE_UP)
			rotate_stack_up(push_swap, to * -1);
		else
			rotate_stack_down(push_swap, to * -1);
		from = get_stack(push_swap, to * -1);
	}
}
