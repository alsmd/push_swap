/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:41:30 by flda-sil          #+#    #+#             */
/*   Updated: 2022/01/14 15:16:43 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (n == 0)
		return (0);
	while ((s1[index] && s2[index]) && index < n)
	{
		if (s1[index] != s2[index] || index == n - 1)
			break ;
		index++;
	}
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
