/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_need_zeroes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:29:02 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/28 11:28:04 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int					check_if_need_zeroes(t_float *obj_flt, int power)
{
	int				i;

	i = SIZE - 1;
	while (obj_flt->parts.fr_buf[i] != '0' && i >= 0)
		i--;
	if (i == power)
		return (0);
	else
		return (1);
}
