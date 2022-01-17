/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 06:15:22 by flda-sil          #+#    #+#             */
/*   Updated: 2022/01/14 15:40:35 by flda-sil         ###   ########.fr       */
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

void	exec_cmd(t_push_swap *push_swap, char *cmd)
{
	if (!ft_strncmp(cmd, "sa\n", ft_strlen(cmd)))
		sa(push_swap);
	else if (!ft_strncmp(cmd, "sb\n", ft_strlen(cmd)))
		sb(push_swap);
	else if (!ft_strncmp(cmd, "ss\n", ft_strlen(cmd)))
		ss(push_swap);
	else if (!ft_strncmp(cmd, "pa\n", ft_strlen(cmd)))
		pa(push_swap);
	else if (!ft_strncmp(cmd, "pb\n", ft_strlen(cmd)))
		pb(push_swap);
	else if (!ft_strncmp(cmd, "ra\n", ft_strlen(cmd)))
		ra(push_swap);
	else if (!ft_strncmp(cmd, "rb\n", ft_strlen(cmd)))
		rb(push_swap);
	else if (!ft_strncmp(cmd, "rr\n", ft_strlen(cmd)))
		rr(push_swap);
	else if (!ft_strncmp(cmd, "rra\n", ft_strlen(cmd)))
		rra(push_swap);
	else if (!ft_strncmp(cmd, "rrb\n", ft_strlen(cmd)))
		rrb(push_swap);
	else if (!ft_strncmp(cmd, "rrr\n", ft_strlen(cmd)))
		rrr(push_swap);
	else
		write(STDERR_FILENO, "Error\n", 6);
}

int	main(int argc, char *argv[])
{
	char		*line;
	t_push_swap	push_swap;

	ft_bzero(&push_swap, sizeof(push_swap));
	push_swap.mode = CHECKER;
	if (argc == 1)
		return (0);
	check_param(&push_swap, argv + 1, argc - 1);
	if (push_swap.error != E_SUCCESS)
	{
		free_stacks(&push_swap);
		return (print_error(push_swap.error));
	}
	line = get_next_line(0);
	while (line)
	{
		exec_cmd(&push_swap, line);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(&push_swap) && push_swap.b == 0)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	free_stacks(&push_swap);
}
