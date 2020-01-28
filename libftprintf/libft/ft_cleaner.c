/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleaner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:26:50 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/10 13:26:54 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_cleaner(void **trash, int index)
{
	if (trash)
	{
		while (index-- != 0)
			ft_memdel(trash + index);
		ft_memdel(trash);
	}
}
