/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:44:00 by mwuckert          #+#    #+#             */
/*   Updated: 2020/01/11 21:22:02 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// char	**ft_strsplit(char const *s, char c)
// {
// 	int		i;
// 	int		**index;
// 	char	**words;

// 	index = ft_getindex((char *)s, c);
// 	if (!s || !index || !(words =
// 				(char **)malloc(sizeof(char *) * (index[0][0] + 1))))
// 		return (NULL);
// 	i = 1;
// 	while (i <= index[0][0])
// 	{
// 		if (!(words[i - 1] = ft_strsub(s, index[i][0], \
// 						index[i][1] - index[i][0] + 1)))
// 		{
// 			ft_cleaner((void **)words, i - 2);
// 			return (NULL);
// 		}
// 		i++;
// 	}
// 	words[i - 1] = NULL;
// 	ft_cleaner((void **)index, i);
// 	return (words);
// }

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**ar;

	if (!s)
		return (0);
	i = 0;
	if (!(ar = (char**)ft_memalloc(sizeof(char*) * (ft_countwordc(s, c) + 1))))
		return (0);
	while (*s)
		if (*s != c)
		{
			if (!(*(ar + i++) = ft_strsub(s, 0, ft_strlenc(s, c))))
			{
				ft_twodarraydel((void**)ar);
				return (0);
			}
			s += ft_strlenc(s, c);
		}
		else
			s++;
	*(ar + i) = 0;
	return (ar);
}
