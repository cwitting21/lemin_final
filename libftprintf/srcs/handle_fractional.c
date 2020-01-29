/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fractional.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:22:35 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/29 17:22:15 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void				handle_high_power_frac(t_float *obj_flt, int index)
{
	int					tmp;
	int					i;

	tmp = 0;
	i = 0;
	ft_bzero(obj_flt->parts.fr_buf, SIZE);
	if (nbr_has_frac_part(obj_flt))
		obj_flt->parts.fr_buf[SIZE - 1] = 5;
	tmp = obj_flt->p_arr[index];
	while (tmp++ < -1)
	{
		i = -1;
		while (++i < SIZE)
			obj_flt->parts.fr_buf[i] = obj_flt->parts.fr_buf[i] * 5;
		normalise_frac(obj_flt->parts.fr_buf);
	}
}

static void				handle_low_power_frac(t_float *obj_flt, int index)
{
	int					curr_pow;
	int					i;
	int					tmp;

	tmp = 0;
	ft_bzero(obj_flt->parts.fr_buf, SIZE);
	obj_flt->parts.fr_buf[SIZE - 1] = 1;
	obj_flt->parts.fr_buf[SIZE - 2] = 2;
	obj_flt->parts.fr_buf[SIZE - 3] = 5;
	curr_pow = obj_flt->p_arr[index] * -1;
	tmp = obj_flt->p_arr[index] + 2;
	while (tmp++ < -1)
	{
		i = -1;
		while (++i < SIZE)
			obj_flt->parts.fr_buf[i] = obj_flt->parts.fr_buf[i] * 5;
		normalise_whole(obj_flt->parts.fr_buf);
		if (check_if_need_zeroes(obj_flt, curr_pow))
			add_zeroes(obj_flt->parts.fr_buf);
	}
}

void					handle_fractional(t_float *obj_flt)
{
	int					index;

	index = obj_flt->parts.i_frac_s - 1;
	ft_bzero(obj_flt->parts.frac, SIZE);
	while (++index <= obj_flt->parts.i_frac_e)
	{
		if (obj_flt->p_arr[index] < -3)
			handle_low_power_frac(obj_flt, index);
		else
			handle_high_power_frac(obj_flt, index);
		sum_arr(obj_flt, 1);
	}
}
