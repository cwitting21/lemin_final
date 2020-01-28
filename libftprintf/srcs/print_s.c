/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:50:14 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/28 11:29:34 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int					print_s(t_print *obj)
{
	char			*str;
	unsigned long	len;

	len = 0;
	str = va_arg(obj->ap, char *);
	obj->start = obj->end;
	if (!str)
		str = "(null)";
	if ((len = ft_strlen(str)) > (unsigned long)obj->fmt.prec
			&& obj->fmt.prec >= 0)
		len = obj->fmt.prec;
	if (obj->fmt.flags[0] != '-' && len < (unsigned long)obj->fmt.width)
		obj->ret += print_space((unsigned long)obj->fmt.width - len);
	write(1, str, len);
	if (obj->fmt.flags[0] == '-' && len < (unsigned long)obj->fmt.width)
		obj->ret += print_space((unsigned long)obj->fmt.width - len);
	obj->ret += len;
	ft_memset(&obj->fmt, 0, obj->szof_fmt);
	obj->fmt.prec = -1;
	return (0);
}
