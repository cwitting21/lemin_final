/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:41:25 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/27 22:04:03 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		get_ants_n_in_end(int *ants_room, int size, int end_index)
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

static int		all_ants_in_end(int *ants_room, int size, int end_index)
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

static void		adjust_starting_pos(int *j, int *ants_n, int *ants_room,
								int end_index)
{
	*j = -1;
	++(*j);
	if (ants_room[*j] == end_index)
	{
		while (ants_room[*j] == end_index)
			++(*j);
		*ants_n += *j;
	}
	--(*j);
}

static int		get_amount_of_avail_ways(t_solution sol)
{
	int			i;
	int			av_ways;

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

static void		malloc_stuff_and_set_ways(t_ants *a, t_map *map, t_solution sol)
{
	a->ants_room = (int*)ft_memalloc(sizeof(int) * map->ants);
	a->ants_way = (int*)ft_memalloc(sizeof(int) * map->ants);
	a->occ_room = (int*)ft_memalloc(sizeof(int) * map->rooms_count);
	set_ways(a->ants_way, sol, map->ants);
}

static void		del_stuff(t_ants a)
{
	ft_memdel((void**)&a.ants_room);
	ft_memdel((void**)&a.ants_way);
	ft_memdel((void**)&a.occ_room);
}

static void		adjust_ants_n_and_print_nl(int *ants_n, t_solution sol,
											t_map *map, t_ants a)
{
	ft_printf("\n");
	*ants_n += get_amount_of_avail_ways(sol);
	*ants_n -= get_ants_n_in_end(a.ants_room, map->ants, map->rooms_count - 1);
}

/*
**	ants_room - current_room of each ant
**	ants_way - each ant hast its own way
**	occ_room - occupied room (1 or 0)
*/

void			move_ants(t_solution s, t_map *map)
{
	int			j;
	int			ants_n;
	t_ants		a;

	ants_n = s.amount_ways;
	ft_bzero(&a, sizeof(t_ants));
	malloc_stuff_and_set_ways(&a, map, s);
	while (!all_ants_in_end(a.ants_room, map->ants, map->rooms_count - 1))
	{
		adjust_starting_pos(&j, &ants_n, a.ants_room, map->rooms_count - 1);
		while (++j < map->ants)
		{
			if (a.ants_room[j] != map->rooms_count - 1 &&
			!a.occ_room[s.rw[a.ants_way[j]].way[a.ants_room[j]].head->data])
			{
				a.occ_room[a.ants_room[j]] = 0;
				a.ants_room[j] = s.rw[a.ants_way[j]].way[a.ants_room[j]].head->data;
				ft_printf("L%d-%s ", j + 1, map->rooms[a.ants_room[j]]);
				if (a.ants_room[j] != map->rooms_count - 1)
					a.occ_room[a.ants_room[j]] = 1;
			}
		}
		adjust_ants_n_and_print_nl(&ants_n, s, map, a);
	}
	del_stuff(a);
}
