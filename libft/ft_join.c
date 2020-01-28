/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 19:54:31 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/28 20:21:38 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_join(char *s1, char *s2, int clean)
{
	char *new_s;

	new_s = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s1)
		free(new_s);
	ft_strcat(new_s, s1);
	ft_strcat(new_s, "\n");
	ft_strcat(new_s, s2);
	ft_strdel(&s1);
	(clean) ? ft_strdel(&s2) : 0;
	return (new_s);
}
