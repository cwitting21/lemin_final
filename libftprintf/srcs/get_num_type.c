/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:15:41 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/29 17:22:15 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static unsigned long long		get_unsigned(t_print *obj)
{
	if (!obj->fmt.size)
		return ((unsigned)va_arg(obj->ap, int));
	else if (obj->fmt.size == 27756)
		return ((unsigned long long)(va_arg(obj->ap, long long)));
	else if (obj->fmt.size == 108)
		return ((unsigned long)va_arg(obj->ap, long));
	else if (obj->fmt.size == 104)
		return ((unsigned short)va_arg(obj->ap, int));
	else if (obj->fmt.size == 26728)
		return ((unsigned char)va_arg(obj->ap, int));
	return (0);
}

static unsigned long long		get_signed(t_print *obj)
{
	if (!obj->fmt.size)
		return ((int)va_arg(obj->ap, int));
	else if (obj->fmt.size == 27756)
		return ((long long)va_arg(obj->ap, long long));
	else if (obj->fmt.size == 108)
		return ((long)va_arg(obj->ap, long));
	else if (obj->fmt.size == 104)
		return ((short)va_arg(obj->ap, int));
	else if (obj->fmt.size == 26728)
		return ((char)va_arg(obj->ap, int));
	return (0);
}

unsigned long long				get_num_type(t_print *obj)
{
	if (obj->fmt.type == 'd' || obj->fmt.type == 'i')
		return (get_signed(obj));
	return (get_unsigned(obj));
}
