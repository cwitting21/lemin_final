/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 23:36:31 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/29 17:22:15 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void				parse_len(t_print *obj)
{
	if (obj->is_neg && !obj->fmt.flags[INDEX_PLUS])
		obj->lens.len_f = -1;
	if (obj->fmt.flags[INDEX_SPACE] && !obj->lens.len_f
		&& !obj->fmt.flags[INDEX_PLUS])
		obj->lens.len_f = -2;
	if (obj->fmt.flags[INDEX_PLUS] && !obj->lens.len_f)
		obj->lens.len_f = 1;
	obj->lens.len_all = (obj->lens.len_f != 0 ? 1 : 0) + obj->flt.all_len;
	if (obj->fmt.prec != -1 && obj->fmt.prec > obj->flt.all_len)
		obj->lens.len_z = obj->fmt.prec - obj->flt.all_len;
	else if (obj->fmt.flags[INDEX_ZERO] && !obj->fmt.flags[INDEX_MINUS]
			&& obj->fmt.width > obj->lens.len_all)
		obj->lens.len_z = obj->fmt.width - obj->lens.len_all;
	obj->lens.len_all += obj->lens.len_z;
	if (obj->lens.len_all < obj->fmt.width)
		obj->lens.len_s = obj->fmt.width - obj->lens.len_all;
	if (obj->fmt.prec != 0 || obj->fmt.flags[INDEX_SHARP])
	{
		obj->lens.len_s--;
		obj->lens.len_z--;
	}
}

static void				format_before(t_print *obj)
{
	if (obj->lens.len_s && !obj->fmt.flags[INDEX_MINUS])
		obj->ret += print_space(obj->lens.len_s);
	if (obj->is_neg)
		obj->ret += write(1, "-", 1);
	else if (!obj->is_neg && obj->fmt.flags[INDEX_PLUS])
		obj->ret += write(1, "+", 1);
	else if (obj->lens.len_f == -2)
		obj->ret += write(1, " ", 1);
	if (obj->lens.len_z)
		obj->ret += print_zero(obj->lens.len_z);
}

static void				format_after(t_print *obj)
{
	if (obj->fmt.flags[INDEX_MINUS] && obj->lens.len_s)
		obj->ret += print_space(obj->lens.len_s);
}

static int				set_index_whole_out(t_float *obj_flt)
{
	int					i;

	i = SIZE;
	while (--i >= 0)
	{
		if (obj_flt->parts.whole[i] > 0)
			return (i);
	}
	return (0);
}

void					output_float(t_float *obj_flt, t_print *obj)
{
	int					i;
	int					tmp[3];

	tmp[0] = 0;
	tmp[1] = -1;
	tmp[2] = -1;
	i = 0;
	i = set_index_whole_out(obj_flt);
	obj->flt.all_len = get_len_float(obj_flt, obj);
	round_float(obj, obj_flt, i);
	parse_len(obj);
	format_before(obj);
	putnbr_float(obj, obj_flt, tmp, i);
	format_after(obj);
	obj->ret += 0;
}
