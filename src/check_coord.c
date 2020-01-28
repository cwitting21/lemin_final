/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_to_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:52:42 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/28 15:05:51 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	free_arr(int **arr, int rooms_n)
{
	int i;

	i = -1;
	while (++i < rooms_n)
		ft_memdel((void**)&arr[i]);
	ft_memdel((void**)&arr);
}

void	check_coord_2(t_map *map, int **arr)
{
	int i;
	int j;

	i = -1;
	i = -1;
	while (++i < map->rooms_count)
	{
		j = i;
		while (++j < map->rooms_count)
			if (arr[i][0] == arr[j][0] && arr[i][1] == arr[j][1])
			{
				free_arr(arr, map->rooms_count);
				free_map(map, 1);
			}
	}
	free_arr(arr, map->rooms_count);
}

void	check_coord(t_map *map)
{
	int		i;
	char	**line;
	char	**r;
	int		**arr;
	int		j;

	i = -1;
	j = -1;
	arr = (int**)ft_memalloc(sizeof(int*) * map->rooms_count);
	while (++i < map->rooms_count)
		arr[i] = (int*)ft_memalloc(sizeof(int) * 2);
	i = -1;
	line = ft_strsplit(map->in->rooms_list, '\n');
	while (line[++i])
	{
		r = ft_strsplit(line[i], ' ');
		if (r[0][0] != '#')
		{
			arr[++j][0] = (int)ft_atoi(r[1]);
			arr[j][1] = (int)ft_atoi(r[2]);
		}
		free_array(r, map, 0);
	}
	free_array(line, map, 0);
	check_coord_2(map, arr);
}
