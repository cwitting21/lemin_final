/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants_help1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 12:53:02 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/29 09:48:59 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			get_amount_of_avail_ways(t_solution sol)
{
	int		i;
	int		av_ways;

	i = -1;
	av_ways = 0;
	while (++i < sol.amount_ways)
	{
		if (sol.rw[i].amount_ants > 0)
		{
			sol.rw[i].amount_ants--;
			av_ways++;
		}
	}
	return (av_ways);
}

void		adjust_ants_n_and_print_nl(int *ants_n, t_solution sol,
											t_map *map, t_ants a)
{
	// ft_printf("\n");
	map->lines_count++;
	*ants_n += get_amount_of_avail_ways(sol);
	*ants_n -= get_ants_n_in_end(a.ants_room, map->ants, map->rooms_count - 1);
}

int			all_ants_in_end(int *ants_room, int size, int end_index)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		if (ants_room[i] != end_index)
			return (0);
	}
	return (1);
}

int			get_ants_n_in_end(int *ants_room, int size, int end_index)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (++i < size)
	{
		if (ants_room[i] == end_index)
			++count;
	}
	return (count);
}
