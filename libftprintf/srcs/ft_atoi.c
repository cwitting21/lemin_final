/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 16:44:57 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/10 16:44:58 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			lead_sign(int sign)
{
	if (sign > 0)
		return (-1);
	return (0);
}

long long			ft_atoi(const char *str)
{
	long long	nb;
	int			sign;

	nb = 0;
	sign = 1;
	while (ft_isspace((int)(*str)))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (ft_isdigit((int)(*str)))
	{
		if ((nb * 10 + *str - '0') / 10 == nb)
			nb = nb * 10 + *str++ - '0';
		else if (sign == -1)
			return (0);
		else
			return (-1);
	}
	return ((long)nb * sign);
}
