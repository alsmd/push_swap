/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:25:26 by flda-sil          #+#    #+#             */
/*   Updated: 2022/01/14 05:32:46 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	free_stacks(t_push_swap *push_swap)
{
	t_stack	*tmp;

	while (push_swap->a)
	{
		tmp = push_swap->a;
		push_swap->a = push_swap->a->next;
		free(tmp);
	}
}

int	main(int argc, char *argv[])
{
	t_push_swap	push_swap;

	ft_bzero(&push_swap, sizeof(push_swap));
	if (argc == 1)
		return (0);
	check_param(&push_swap, argv + 1, argc - 1);
	if (push_swap.error != E_SUCCESS)
	{
		free_stacks(&push_swap);
		return (print_error(push_swap.error));
	}
	if (get_chunk_size(&push_swap, push_swap.a) == 3)
		sort_three(&push_swap);
	else
		sort(&push_swap);
	free_stacks(&push_swap);
}
