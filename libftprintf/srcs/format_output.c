/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 16:45:07 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/28 11:28:12 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		format_output(t_print *obj)
{
	if (obj->fmt.type == '%')
		return (print_percentage(obj));
	else if (obj->fmt.type == 's')
		return (print_s(obj));
	else if (obj->fmt.type == 'c')
		return (print_c(obj));
	else if (obj->fmt.type == 'd' || obj->fmt.type == 'i')
		return (print_d(obj));
	else if (obj->fmt.type == 'x' || obj->fmt.type == 'X')
		return (print_x(obj));
	else if (obj->fmt.type == 'o')
		return (print_o(obj));
	else if (obj->fmt.type == 'p')
		return (print_p(obj));
	else if (obj->fmt.type == 'u')
		return (print_u(obj));
	else if (obj->fmt.type == 'f')
		return (handle_float(obj));
	else if (obj->fmt.type == 'b')
		return (print_binary(obj));
	return (0);
}
