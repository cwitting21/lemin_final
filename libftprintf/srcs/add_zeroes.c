/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_zeroes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:29:37 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/28 11:27:13 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void				add_zeroes(char *str)
{
	int				i;
	int				tmp;

	i = -1;
	tmp = str[0];
	while (++i < SIZE)
		str[i] = str[i + 1];
	str[SIZE - 1] = tmp;
}
