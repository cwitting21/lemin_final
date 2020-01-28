/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 23:04:57 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/28 11:29:57 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int		scan_frac_for_nonzero_value(t_float *obj_flt)
{
	int			i;

	i = SIZE - 1;
	while (--i >= 0)
	{
		if (obj_flt->parts.frac[i] > 0)
			return (1);
	}
	return (0);
}

void			normalise_test2(t_float *obj_flt, int start)
{
	int			i;

	i = SIZE - start - 1;
	while (++i < SIZE)
	{
		if (obj_flt->parts.frac[i] >= 10)
		{
			obj_flt->parts.frac[i + 1] += obj_flt->parts.frac[i] / 10;
			obj_flt->parts.frac[i] %= 10;
		}
	}
	if (obj_flt->parts.frac[SIZE - 1] >= 10)
	{
		obj_flt->parts.whole[0] += 1;
		obj_flt->parts.frac[SIZE - 1] %= 10;
		normalise_whole(obj_flt->parts.whole);
	}
}

void			normalise_frac_prec_min_one(t_float *obj_flt)
{
	int			i;

	i = SIZE - 8;
	while (++i < SIZE)
	{
		if (obj_flt->parts.frac[SIZE - 1] >= 10)
			obj_flt->parts.whole[0] += 1;
		if (obj_flt->parts.frac[i] / 10 > 0)
		{
			obj_flt->parts.frac[i + 1] += obj_flt->parts.frac[i] / 10;
			obj_flt->parts.frac[i] %= 10;
		}
	}
}

void			round_float(t_print *obj, t_float *obj_flt, int i)
{
	i += 0;
	if (obj->fmt.prec == 0)
	{
		if ((obj_flt->parts.frac[SIZE - 1] >= 5) &&
			scan_frac_for_nonzero_value(obj_flt))
			obj_flt->parts.whole[0] += 1;
		normalise_whole(obj_flt->parts.whole);
	}
	if (obj->fmt.prec == -1)
	{
		if (obj_flt->parts.frac[SIZE - 7] >= 5)
			obj_flt->parts.frac[SIZE - 6] += 1;
		normalise_frac_prec_min_one(obj_flt);
	}
	if (obj->fmt.prec > 0)
	{
		if (obj_flt->parts.frac[SIZE - obj->fmt.prec - 1] >= 5)
		{
			obj_flt->parts.frac[SIZE - obj->fmt.prec] += 1;
			normalise_test2(obj_flt, obj->fmt.prec);
		}
	}
}
