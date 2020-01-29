/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_has_frac_part.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:49:57 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/29 17:22:15 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int					nbr_has_frac_part(t_float *obj_flt)
{
	int				i;

	i = -1;
	while (++i <= obj_flt->parts.i_frac_e)
	{
		if (obj_flt->p_arr[i] < 0)
			return (1);
	}
	return (0);
}
