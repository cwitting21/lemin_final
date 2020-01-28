/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:01:43 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/10 14:01:44 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len;
	size_t len2;
	size_t summ;
	size_t i;

	i = 0;
	len = ft_strlen(dst);
	len2 = ft_strlen(src);
	summ = len + len2;
	if (size <= len)
		return (len2 + size);
	while (i < (size - len - 1) && src[i] != '\0')
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';
	return (summ);
}
