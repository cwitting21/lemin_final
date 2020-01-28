/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:46:06 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/10 13:46:07 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_printbits(unsigned long long bits, int lenbit)
{
	unsigned long long	mask;
	int					len;
	int					item;

	mask = 1;
	len = 0;
	item = 0;
	while (len++ < (lenbit == 0 ? 64 : lenbit))
	{
		ft_putnbr(bits & mask ? 1 : 0);
		if (!(len % 4))
			ft_putstr(" ");
		if (len == (lenbit == 32 ? 16 : 32))
			ft_putchar('\n');
		mask <<= 1;
	}
	ft_putstr("\n");
	while (item++ < (lenbit == 64 ? 39 : 19))
		ft_putchar('~');
	ft_putstr("\n");
}
