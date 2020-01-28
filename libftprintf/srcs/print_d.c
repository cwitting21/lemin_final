/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:34:14 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/28 11:29:25 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void		parse_len(t_print *obj)
{
	if (obj->fmt.flags[INDEX_SPACE] && !obj->lens.len_f
		&& !obj->fmt.flags[INDEX_PLUS])
		obj->lens.len_f = -2;
	if (obj->fmt.flags[INDEX_PLUS] && !obj->lens.len_f)
		obj->lens.len_f = 1;
	obj->lens.len_all = (obj->lens.len_f != 0 ? 1 : 0) + obj->lens.len_num;
	if (obj->fmt.prec != -1 && obj->fmt.prec > obj->lens.len_num)
		obj->lens.len_z = obj->fmt.prec - obj->lens.len_num;
	else if (obj->fmt.flags[INDEX_ZERO] && !obj->fmt.flags[INDEX_MINUS]
			&& obj->fmt.prec == -1 && obj->fmt.width > obj->lens.len_all)
		obj->lens.len_z = obj->fmt.width - obj->lens.len_all;
	obj->lens.len_all += obj->lens.len_z;
	if (obj->lens.len_all < obj->fmt.width)
		obj->lens.len_s = obj->fmt.width - obj->lens.len_all;
}

static void		format_before(t_print *obj)
{
	if (obj->lens.len_s && !obj->fmt.flags[INDEX_MINUS])
		obj->ret += print_space(obj->lens.len_s);
	if (obj->lens.len_f == -1)
		obj->ret += write(1, "-", 1);
	else if (obj->lens.len_f > 0)
		obj->ret += write(1, "+", 1);
	else if (obj->lens.len_f == -2)
		obj->ret += write(1, " ", 1);
	if (obj->lens.len_z)
		obj->ret += print_zero(obj->lens.len_z);
}

static void		format_after(t_print *obj)
{
	if (obj->fmt.flags[INDEX_MINUS] && obj->lens.len_s)
		obj->ret += print_space(obj->lens.len_s);
}

int				print_d(t_print *obj)
{
	long long	d;

	d = (long long)get_num_type(obj);
	if (d < 0)
	{
		d *= -1;
		obj->lens.len_f = -1;
	}
	if (d || (obj->fmt.prec && !d))
		obj->lens.len_num = len_num_base(d, 10);
	parse_len(obj);
	format_before(obj);
	if (d || (obj->fmt.prec && !d))
		putnbr_base(obj, d, 10);
	format_after(obj);
	obj->start = obj->end;
	ft_bzero(&obj->lens, obj->szof_lens);
	ft_bzero(&obj->fmt, obj->szof_fmt);
	obj->fmt.prec = -1;
	return (0);
}
