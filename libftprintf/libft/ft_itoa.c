/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:28:23 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/10 13:28:24 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			count_len(long long int n)
{
	size_t len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -(n);
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char					*ft_itoa(int n)
{
	long long int		res;
	size_t				x;
	size_t				len;
	char				*out;

	res = n;
	len = count_len(res);
	if (!(out = ft_strnew(len)))
		return (NULL);
	x = 0;
	while (len-- != x)
	{
		if (res < 0)
		{
			res = -(res);
			out[0] = '-';
			x++;
		}
		out[len] = res % 10 + '0';
		res = res / 10;
	}
	return (out);
}
