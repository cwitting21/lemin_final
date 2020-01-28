/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:30:36 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/10 13:36:06 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

void	*ft_memset(void *d, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
		((unsigned char *)d)[i++] = (unsigned char)c;
	return (d);
}
