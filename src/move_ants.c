/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:41:25 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/28 14:44:45 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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

static void		malloc_stuff_and_set_ways(t_ants *a, t_map *map, t_solution sol,
																	int *ants_n)
{
	*ants_n = sol.amount_ways;
	a->ants_room = (int*)ft_memalloc(sizeof(int) * map->ants);
	a->ants_way = (int*)ft_memalloc(sizeof(int) * map->ants);
	a->occ_room = (int*)ft_memalloc(sizeof(int) * map->rooms_count);
	set_ways(a->ants_way, sol, map->ants);
}

static void		del_stuff(t_ants a, int lines, int code)
{
	if (code == 1)
		printf("---- %d lines ----\n", lines);
	ft_memdel((void**)&a.ants_room);
	ft_memdel((void**)&a.ants_way);
	ft_memdel((void**)&a.occ_room);
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

	ft_bzero(&a, sizeof(t_ants));
	malloc_stuff_and_set_ways(&a, map, s, &ants_n);
	while (!all_ants_in_end(a.ants_room, map->ants, map->rooms_count - 1))
	{
		adjust_starting_pos(&j, &ants_n, a.ants_room, map->rooms_count - 1);
		while (++j < map->ants)
		{
			if (a.ants_room[j] != map->rooms_count - 1 &&
			!a.occ_room[s.rw[a.ants_way[j]].way[a.ants_room[j]].head->data])
			{
				a.occ_room[a.ants_room[j]] = 0;
				a.ants_room[j] =
							s.rw[a.ants_way[j]].way[a.ants_room[j]].head->data;
				// ft_printf("L%d-%s ", j + 1, map->rooms[a.ants_room[j]]);
				if (a.ants_room[j] != map->rooms_count - 1)
					a.occ_room[a.ants_room[j]] = 1;
			}
		}
		adjust_ants_n_and_print_nl(&ants_n, s, map, a);
	}
	del_stuff(a, map->lines_count, map->options[0]);
}
