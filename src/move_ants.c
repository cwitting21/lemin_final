/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:41:25 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/26 23:04:00 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// static void	print_ants_way(int *ants_way, int size)
// {
// 	int		i;

// 	i = -1;
// 	printf("\n");
// 	while (++i < size)
// 		printf(" %d ", ants_way[i]);
// 	printf("\n");
// }

static void	set_ways(int *ants_way, t_solution sol, int size)
{
	int		i;
	int		*tmp; // for storing amount of ants for each way
	int		tmp_i;

	tmp_i = -1;
	i = 0;
	tmp = (int*)ft_memalloc(sizeof(int) * sol.amount_ways);
	while (++tmp_i < sol.amount_ways)
		tmp[tmp_i] = sol.ready_ways[tmp_i].amount_ants;
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

static int	get_amount_of_ants_in_end(int *ants_room, int size, int end_index)
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

static int	all_ants_in_end(int *ants_room, int size, int end_index)
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

static void	adjust_starting_pos(int *j, int *ants_n, int *ants_room, int end_index)
{
	++(*j);
	if (ants_room[*j] == end_index)
	{
		while (ants_room[*j] == end_index)
			++(*j);
		*ants_n += *j;
	}
	--(*j);
}

static int	get_amount_of_avail_ways(t_solution *sol)
{
	int		i;
	int		av_ways;

	i = -1;
	av_ways = 0;
	while (++i < sol->amount_ways)
	{
		if (sol->ready_ways[i].amount_ants > 0)
		{
			sol->ready_ways[i].amount_ants--;
			av_ways++;
		}
	}
	return (av_ways);
}

void		move_ants(t_solution sol, t_map *map)
{
	int		*ants_room; // current room of each ant
	int		*ants_way; // each ant has its own way
	int		j;
	int		ants_n;
	int		ants_in_end = 0;
	int		*occ_room; // occupied room

	ants_n = sol.amount_ways;
	map->rooms_count += 0;
	sol.amount_lines += 0;
	ants_room = (int*)ft_memalloc(sizeof(int) * map->ants);
	ants_way = (int*)ft_memalloc(sizeof(int) * map->ants);
	occ_room = (int*)ft_memalloc(sizeof(int) * map->rooms_count);
	set_ways(ants_way, sol, map->ants);
	while (!all_ants_in_end(ants_room, map->ants, map->rooms_count - 1))
	{
		j = -1;
		adjust_starting_pos(&j, &ants_n, ants_room, map->rooms_count - 1);
		while (++j < map->ants)
		{
			if (ants_room[j] != map->rooms_count - 1 && !occ_room[sol.ready_ways[ants_way[j]].way[ants_room[j]].head->data]) // if an ant is not at the end, move it
			{
				occ_room[ants_room[j]] = 0;
				ants_room[j] = sol.ready_ways[ants_way[j]].way[ants_room[j]].head->data; //
				// printf("L%d-%s ", j + 1, map->rooms[ants_room[j]]);
				if (ants_room[j] == map->rooms_count - 1)
					ants_in_end++;
				else
					occ_room[ants_room[j]] = 1;
			}
		}
		// printf("\n");
		ants_n += get_amount_of_avail_ways(&sol);
		ants_n -= get_amount_of_ants_in_end(ants_room, map->ants, map->rooms_count - 1);
	}
	ft_memdel((void**)&ants_room);
	ft_memdel((void**)&ants_way);
	ft_memdel((void**)&occ_room);
}
