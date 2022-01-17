/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:26:11 by flda-sil          #+#    #+#             */
/*   Updated: 2022/01/14 05:31:02 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	is_number(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

static int	get_overflow_n(int sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}

long int	ft_atoi(const char *nptr)
{
	size_t		index;
	int			sign;
	long int	re;

	sign = 1;
	re = 0;
	index = 0;
	while (is_space(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (is_number(nptr[index]))
	{
		if (index >= 18)
			return (get_overflow_n(sign));
		re = (re * 10) + (nptr[index++] - 48);
	}
	return (re * sign);
}
