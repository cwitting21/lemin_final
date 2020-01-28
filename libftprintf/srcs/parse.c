/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 23:42:04 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/28 11:29:20 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void			parse(t_print *obj)
{
	parse_flags(obj);
	parse_width(obj);
	parse_prec(obj);
	parse_size(obj);
	parse_type(obj);
	obj->start = obj->end;
}
