/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:54:11 by flda-sil          #+#    #+#             */
/*   Updated: 2022/01/14 05:35:40 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	is_not_number(char *string)
{
	if (*string == '-' || *string == '+')
		string++;
	while (*string)
	{
		if (*string < 48 || *string > 57)
			return (1);
		string++;
	}
	return (0);
}

static int	qnt_digits(char *numb)
{
	int	index;

	index = 0;
	if (*numb == '-' || *numb == '+')
		numb++;
	while (*numb)
	{
		index++;
		numb++;
	}
	return (index);
}

int	check_param(t_push_swap *push_swap, char *params[], int size)
{
	long int	number;
	long int	min_number;
	int			index;

	index = 0;
	min_number = (size_t)(((size_t) INT_MAX * -1) - 1);
	while (index < size)
	{
		if (is_not_number(params[index]))
			return (push_swap->error = E_IS_NOT_NUMBER);
		number = ft_atoi(params[index]);
		if (number > INT_MAX || number < min_number || \
			qnt_digits(params[index]) > 10)
			return (push_swap->error = E_OUT_OF_INT_LIMIT);
		if (is_in_stack(push_swap, (int) number))
			return (push_swap->error = E_DUPLICATE_NUMBER);
		add_to_stack(push_swap, (int) number);
		index++;
	}
	return (0);
}
