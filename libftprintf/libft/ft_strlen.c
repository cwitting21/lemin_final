/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:01:09 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/10 14:01:10 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

size_t	ft_strlen(const char *s)
{
	size_t count;

	count = 0;
	if (s)
		while (s[count] != '\0')
			count++;
	return (count);
}
