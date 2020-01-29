/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:47:49 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/29 17:22:15 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void				parse_len(t_print *obj)
{
	obj->lens.len_all = obj->lens.len_num;
	if (obj->fmt.prec != -1 && obj->fmt.prec > obj->lens.len_num)
		obj->lens.len_z = obj->fmt.prec - obj->lens.len_num;
	if (obj->fmt.flags[4] && !obj->fmt.flags[0] && obj->fmt.prec == -1
			&& obj->fmt.width > obj->lens.len_all)
	{
		obj->lens.len_z = obj->fmt.width - obj->lens.len_all;
	}
	obj->lens.len_all += obj->lens.len_z;
	if (obj->lens.len_all < obj->fmt.width)
		obj->lens.len_s = obj->fmt.width - obj->lens.len_all;
	if (obj->fmt.prec == 0)
		obj->lens.len_s = obj->fmt.width;
}

static void				format_before(t_print *obj)
{
	if (obj->lens.len_s && !obj->fmt.flags[0])
		obj->ret += print_space(obj->lens.len_s);
	if (obj->lens.len_z)
		obj->ret += print_zero(obj->lens.len_z);
}

static void				format_after(t_print *obj)
{
	if (obj->fmt.flags[0] && obj->lens.len_s)
		obj->ret += print_space(obj->lens.len_s);
}

int						print_u(t_print *obj)
{
	unsigned long long	d;

	if (!(d = get_num_type(obj)))
		obj->lens.len_num++;
	obj->lens.len_num = len_num_base(d, 10);
	parse_len(obj);
	format_before(obj);
	if (d || (obj->fmt.prec && !d))
		putnbr_base(obj, d, 10);
	format_after(obj);
	obj->start = obj->end;
	ft_memset(&obj->lens, 0, obj->szof_lens);
	ft_memset(&obj->fmt, 0, obj->szof_fmt);
	obj->fmt.prec = -1;
	return (0);
}
