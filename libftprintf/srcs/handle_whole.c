/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_whole.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:22:27 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/28 11:28:48 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void				handle_whole(t_float *obj_flt)
{
	int				i;
	int				tmp;
	int				index;

	index = (!obj_flt->parts.i_frac_s ? obj_flt->parts.i_frac_e :
	obj_flt->parts.i_frac_s - 1);
	ft_bzero(obj_flt->parts.whole, SIZE);
	while (index >= 0)
	{
		ft_bzero(obj_flt->p_buf.buf, SIZE);
		obj_flt->p_buf.buf[0] = (obj_flt->p_arr[index] >= 1 ? 2 : 1);
		tmp = obj_flt->p_arr[index];
		if (tmp > 0)
		{
			while (tmp-- > 1)
			{
				i = -1;
				while (++i < SIZE)
					obj_flt->p_buf.buf[i] *= 2;
				normalise_whole(obj_flt->p_buf.buf);
			}
		}
		sum_arr(obj_flt, 0);
		--index;
	}
}
