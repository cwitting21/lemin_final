/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 16:37:45 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/29 17:22:15 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void			putnbr_float(t_print *obj, t_float *obj_flt, int tmp[3], int i)
{
	int			m;

	m = SIZE - 1;
	while (++tmp[1] < SIZE)
		obj_flt->parts.frac[tmp[1]] += '0';
	while (++tmp[2] < SIZE)
		obj_flt->parts.whole[tmp[2]] += '0';
	if (nbr_has_whole_part(obj_flt))
	{
		while (i >= 0)
			obj->ret += write(1, &obj_flt->parts.whole[i--], 1);
	}
	else
		obj->ret += write(1, "0", 1);
	if (obj->fmt.prec != 0 || obj->fmt.flags[INDEX_SHARP])
		obj->ret += write(1, ".", 1);
	if (obj->fmt.prec == -1)
	{
		while (tmp[0]++ < 6)
			obj->ret += write(1, &obj_flt->parts.frac[m--], 1);
	}
	else
		while (obj->fmt.prec-- > 0)
			obj->ret += write(1, &obj_flt->parts.frac[m--], 1);
}
