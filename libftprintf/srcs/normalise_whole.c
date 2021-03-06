/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalise_whole.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:27:17 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/29 17:22:15 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		normalise_whole(char *str)
{
	int		i;

	i = 0;
	while (i < SIZE)
	{
		str[i + 1] += str[i] / 10;
		str[i++] %= 10;
	}
}
