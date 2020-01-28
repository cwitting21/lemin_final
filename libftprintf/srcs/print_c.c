/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:35:01 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/28 11:29:23 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		print_c(t_print *obj)
{
	char c;

	c = (char)va_arg(obj->ap, int);
	if (obj->fmt.flags[0] != '-' && obj->fmt.width > 1)
		obj->ret += print_space(obj->fmt.width - 1);
	obj->ret += write(1, &c, 1);
	if (obj->fmt.flags[0] && obj->fmt.width > 1)
		obj->ret += print_space(obj->fmt.width - 1);
	obj->start = obj->end;
	ft_memset(&obj->fmt, 0, obj->szof_fmt);
	obj->fmt.prec = -1;
	return (0);
}
