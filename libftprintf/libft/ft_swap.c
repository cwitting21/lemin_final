/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:46:26 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/10 13:46:27 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_swap(void **a, void **b)
{
	void **c;

	if (a && b)
	{
		if (!(c = (void **)malloc(sizeof(void *) * 1)))
			return (NULL);
		*c = *a;
		*a = *b;
		*b = *c;
		ft_cleaner(c, 1);
		return (a);
	}
	return (NULL);
}
