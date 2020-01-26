/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 17:05:33 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/26 22:41:26 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	initialize_map(t_map *map)
{
	if (!(map->val = (t_valid *)ft_memalloc(sizeof(t_valid))))
		exit(1);
	if (!(map->in = (t_input *)ft_memalloc(sizeof(t_input))))
		exit(1);
	// map->in->refact_split = (char**)ft_memalloc(sizeof(char*) * 100000); // random value! SEG
	map->in->link_list = ft_strnew(1);
	map->in->ants_list = ft_strnew(1);
	map->in->rooms_list = ft_strnew(1);
	map->rooms_count = 0;
	map->ants = 0;
	map->val->part = 0;
	map->curr_room = 0;
	map->w_ind = 0;
	map->val->init_2 = 0;
	map->val->good[0] = 0;
	map->val->good[1] = 0;
	map->rooms = NULL;
	map->matrix = NULL;
	map->way = NULL;
	ft_bzero(map->dup_arr, 10000 * sizeof(t_bool)); // change 100 later
}

void	initialize_map_2(t_map *map)
{
	int i;
	int j;

	i = -1;
	map->val->init_2 = 1;
	// map->way = (int*)ft_memalloc(sizeof(int) * 100000); // random value! SEG
	map->matrix = (int**)ft_memalloc(sizeof(int*) * map->rooms_count);
	map->rooms = (char**)ft_memalloc(sizeof(char*) * (map->rooms_count + 1));
	map->in_way = (int*)ft_memalloc(sizeof(int) * map->rooms_count);
	if (!(map->ways = (t_ways*)ft_memalloc(sizeof(t_ways) * 60))) // change 10 to smth else
			ft_exit("map->ways");
	while (++i < map->rooms_count)
	{
		// map->way[i] = -1;
		map->rooms[i] = NULL;
		map->matrix[i] = (int*)ft_memalloc(sizeof(int) * map->rooms_count);
		j = -1;
		while (map->matrix[i][++j])
			map->matrix[i][j] = 0;
	}
	map->rooms[i] = NULL;
	// map->way[0] = 0;
}


void	free_map(t_map *map, int code)
{
	int i;

	free(map->in->link_list);
	free(map->in->ants_list);
	free(map->in->rooms_list);
	if (map->val->init_2)
	{
		free(map->way);
		free_array(map->rooms, map, 0);
		i = -1;
		while (++i < map->rooms_count)
			free(map->matrix[i]);
		free(map->matrix);
	}
	free(map->val);
	free(map);
	if (code)
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(1);
	}
	exit(0);
}
