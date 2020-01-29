/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:37:42 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/29 17:22:15 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int		size_cap_l(t_print *obj)
{
	obj->fmt.size = *((char *)obj->end);
	++obj->end;
	return (0);
}

static int		size_two(t_print *obj)
{
	obj->fmt.size = *((short *)obj->end);
	obj->end += 2;
	return (0);
}

static int		size_one(t_print *obj)
{
	obj->fmt.size = *((char *)obj->end);
	++obj->end;
	return (0);
}

int				parse_size(t_print *obj)
{
	if ((*obj->end == 'l' && *(obj->end + 1) == 'l')
			|| (*obj->end == 'h' && *(obj->end + 1) == 'h'))
		return (size_two(obj));
	else if (*obj->end == 'l' || *obj->end == 'h')
		return (size_one(obj));
	else if (*obj->end == 'L')
		return (size_cap_l(obj));
	return (0);
}
