/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:42:07 by flda-sil          #+#    #+#             */
/*   Updated: 2022/01/14 05:30:33 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	is_in(int *array, int n, int size)
{
	while (size)
	{
		size--;
		if (array[size] == n)
			return (1);
	}
	return (0);
}
