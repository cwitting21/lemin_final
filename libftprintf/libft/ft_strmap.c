/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:01:50 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/10 14:01:51 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	size_t	i;
	char	*res;

	if (s && f)
	{
		len = ft_strlen(s);
		i = 0;
		res = ft_strnew(len);
		if (res)
		{
			while (len-- != 0)
				res[i++] = f(*s++);
			return (res);
		}
	}
	return (NULL);
}
