/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:52:15 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/29 17:22:15 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void				parse_len_2(t_print *obj)
{
	if (obj->fmt.width > obj->lens.len_num)
	{
		if (obj->fmt.flags[INDEX_ZERO] && obj->fmt.prec < 0)
			obj->lens.len_z = obj->fmt.width - obj->lens.len_num;
		else
			obj->lens.len_s = obj->fmt.width - obj->lens.len_num;
	}
}

static void				parse_len(t_print *obj, unsigned long long d)
{
	if (obj->fmt.prec)
		obj->lens.len_num = len_num_base(d, 8);
	else if (obj->fmt.flags[INDEX_SHARP])
		obj->lens.len_num++;
	if (obj->fmt.prec > obj->lens.len_num)
	{
		obj->lens.len_z = obj->fmt.prec - obj->lens.len_num;
		obj->lens.len_num = obj->fmt.prec;
	}
	parse_len_2(obj);
	if (obj->fmt.flags[INDEX_SHARP] && !obj->lens.len_z)
	{
		if (d)
		{
			obj->lens.len_z = 1;
			obj->lens.len_s--;
		}
		else if (!obj->fmt.prec)
			obj->lens.len_z = 1;
	}
}

static void				format_before(t_print *obj)
{
	if (!obj->fmt.flags[INDEX_MINUS])
		obj->ret += print_space_o(&obj->lens.len_s);
	obj->ret += print_zero_o(&obj->lens.len_z);
}

static void				format_after(t_print *obj)
{
	obj->ret += print_space_o(&obj->lens.len_s);
}

int						print_o(t_print *obj)
{
	unsigned long long	d;

	d = get_num_type(obj);
	if (obj->fmt.flags[INDEX_MINUS] && obj->fmt.flags[INDEX_ZERO])
		obj->fmt.flags[INDEX_ZERO] = 0;
	parse_len(obj, d);
	format_before(obj);
	if (d || obj->fmt.prec)
		putnbr_base(obj, d, 8);
	format_after(obj);
	obj->start = obj->end;
	ft_memset(&obj->lens, 0, obj->szof_lens);
	ft_memset(&obj->fmt, 0, obj->szof_fmt);
	obj->fmt.prec = -1;
	return (0);
}
