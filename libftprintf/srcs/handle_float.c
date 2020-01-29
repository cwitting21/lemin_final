/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:20:25 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/29 17:22:15 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void		set_index_for_fractional(t_float *obj_flt)
{
	int				i;

	i = obj_flt->k;
	while (i >= 0)
	{
		if (obj_flt->p_arr[i] < 0)
			obj_flt->parts.i_frac_s = i;
		i--;
	}
}

static void		parse_power(unsigned long mnt, unsigned short exp,
				t_float *obj_flt)
{
	int					i;
	int					e;

	i = 64;
	ft_bzero((obj_flt)->p_arr, 64);
	e = exp - 16383;
	while (i-- > 0)
	{
		if (mnt & 0x8000000000000000)
			(obj_flt)->p_arr[obj_flt->k++] = e;
		e--;
		mnt <<= 1;
	}
	obj_flt->k--;
	set_index_for_fractional(obj_flt);
	obj_flt->parts.i_frac_e = obj_flt->k;
	if (nbr_has_whole_part(obj_flt))
		handle_whole(obj_flt);
	if (nbr_has_frac_part(obj_flt))
		handle_fractional(obj_flt);
}

int				handle_float(t_print *obj)
{
	t_float		obj_flt;
	union u_ld	ld;

	ft_bzero(&obj_flt, sizeof(t_float));
	ld.ldb = (long double)(extract_float(obj));
	parse_power(ld.bits.mnt, ld.bits.exp, &obj_flt);
	if (ld.bits.s)
		obj->is_neg = 1;
	output_float(&obj_flt, obj);
	return (0);
}
