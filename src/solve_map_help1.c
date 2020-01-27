/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map_help1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:59:04 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/27 20:59:12 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			init_data1(int *i, int *bfs_found_way)
{
	*i = 0;
	*bfs_found_way = 1;
}

void			help_func2(int *in_way, t_map *map, int *tmp, int i)
{
	*in_way = 1;
	add_to_ready_way(map, tmp[0], tmp[1], i);
}

void			help_func3(t_map *map, int *tmp, int i)
{
	if (tmp[0] == map->rooms_count - 1)
		add_to_ready_way(map, tmp[0], tmp[1], i);
}

void			recalculate_data1(int *tmp2, int *tmp, int data)
{
	*tmp2 = *tmp;
	*tmp = data;
}

void			recalculate_data2(int *i, t_al_node **start)
{
	++(*i);
	*start = (*start)->next;
}
