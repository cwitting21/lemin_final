/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:03:05 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/10 14:03:06 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	size;

	size = ft_strlen(src);
	if (size < len)
	{
		ft_memcpy(dst, src, size);
		ft_bzero(dst + size, len - size);
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
