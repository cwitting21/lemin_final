/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 12:20:53 by astamm            #+#    #+#             */
/*   Updated: 2020/01/11 21:23:37 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	if (s)
	{
		i = 0;
		subs = ft_strnew(len);
		while (len-- != 0 && subs && s[start])
			subs[i++] = s[start++];
		return (subs);
	}
	return (NULL);
}

// char	*ft_strsub(char const *s, unsigned int start, size_t len)
// {
// 	char	*new;
// 	size_t	i;

// 	i = 0;
// 	if (!s)
// 		return (0);
// 	if (len + 1 == 0)
// 		return (0);
// 	if (!(new = (char*)malloc(sizeof(char) * len + 1)))
// 		return (0);
// 	while (i < len)
// 		new[i++] = s[start++];
// 	new[i] = '\0';
// 	return (new);
// }
