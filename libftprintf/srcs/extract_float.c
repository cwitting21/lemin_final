/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 22:04:54 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/28 11:28:10 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

long double			extract_float(t_print *obj)
{
	if (!obj->fmt.size)
		return ((long double)(va_arg(obj->ap, double)));
	if (obj->fmt.size == 108)
		return ((long double)(va_arg(obj->ap, double)));
	else if (obj->fmt.size == 76)
		return ((long double)va_arg(obj->ap, long double));
	return (0);
}
