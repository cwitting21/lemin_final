/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:27:13 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/10 13:27:14 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		**fresh_arry(int size)
{
	int	**new;
	int	i;

	i = 0;
	if (!(new = (int **)malloc(sizeof(int *) * size + 1)))
		return (NULL);
	while (i < size + 1)
	{
		if (!(new[i] = (int *)malloc(sizeof(int) * 2)))
		{
			ft_cleaner((void **)new, i);
			return (NULL);
		}
		new[i][0] = 0;
		new[i++][1] = 0;
	}
	return (new);
}

int				**ft_getindex(char *s, char c)
{
	int		**indexs;
	size_t	i;
	int		w;

	if (s)
		w = ft_cwords(s, c);
	if (!s || !(indexs = fresh_arry(w)))
		return (NULL);
	indexs[0][0] = w;
	i = 0;
	w = 1;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && i > 0 && s[i - 1] == c))
			indexs[w][0] = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			indexs[w++][1] = i;
		i++;
	}
	return (indexs);
}
