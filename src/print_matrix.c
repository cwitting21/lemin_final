/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 00:14:51 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/17 00:14:53 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void  header(t_map *m)
{
	int i;

	i = -1;
	ft_putstr("\n\n");
	ft_putstr("\t       ");
	while (++i < m->rooms_count)
	{
		ft_putchar(' ');
		// ft_putnbr((i > 9) ? (i % 10) : i);
		ft_putnbr(i);
	}
	ft_putstr("\n\n");
}

void    print_matrix(t_map *m)
{
	int i;
	int j;

	header(m);
	i = -1;							// i - number of string, j - number of column
	while (++i < m->rooms_count)
	{
    	ft_putchar('\t');
    	// ft_putnbr((i > 9) ? (i % 10) : i);
		ft_putnbr(i);
    	// ft_putstr("   ");
		ft_putchar('\t');
  		j = -1;
  		while (++j < m->rooms_count)
  		{
    		ft_putnbr(m->matrix[i][j]);
    		ft_putchar(' ');
		}
  		ft_putstr("\t\t");
  		ft_putchar('[');
  		ft_putnbr(i);
		ft_putstr("] - ");
		ft_putendl(m->rooms[i]);
	}
	ft_putstr("\n\n");
}
