/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:48:12 by flda-sil          #+#    #+#             */
/*   Updated: 2022/01/14 15:23:13 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	print_error(int error)
{
	char	*message;

	if (error == E_IS_NOT_NUMBER)
		message = "Error\n";
	if (error == E_OUT_OF_INT_LIMIT)
		message = "Error\n";
	if (error == E_DUPLICATE_NUMBER)
		message = "Error\n";
	write(STDERR_FILENO, message, ft_strlen(message));
	return (error);
}
