/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:36:46 by flda-sil          #+#    #+#             */
/*   Updated: 2022/01/14 05:31:13 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*r;

	if (nmemb * size > INT_MAX)
		return (0);
	r = malloc(nmemb * size);
	if (r)
	{
		ft_bzero(r, nmemb * size);
		return (r);
	}
	return (0);
}
