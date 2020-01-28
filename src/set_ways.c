/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ways.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 21:27:06 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/27 21:27:13 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
**	calculates the way of each ant
*/

void	set_ways(int *ants_way, t_solution sol, int size)
{
	int		i;
	int		*tmp;
	int		tmp_i;

	tmp_i = -1;
	i = 0;
	tmp = (int*)ft_memalloc(sizeof(int) * sol.amount_ways);
	while (++tmp_i < sol.amount_ways)
		tmp[tmp_i] = sol.rw[tmp_i].amount_ants;
	while (i < size)
	{
		tmp_i = 0;
		while (tmp_i < sol.amount_ways)
		{
			if (tmp[tmp_i] > 0)
				ants_way[i] = tmp_i;
			else
				i--;
			tmp[tmp_i]--;
			tmp_i++;
			i++;
		}
	}
	ft_memdel((void**)&tmp);
}
