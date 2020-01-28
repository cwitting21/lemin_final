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

void	check_coord(t_map *map)
{
	int		i;
	char	**line;
	char	**r;
	int		j;
	int		arr[map->rooms_count][map->rooms_count];

	i = -1;
	j = -1;
	line = ft_strsplit(map->in->rooms_list, '\n');
	while (line[++i])
	{
		r = ft_strsplit(line[i], ' ');
		if (r[0][0] != '#')
		{
			arr[++j][0] = ft_atoi(r[1]);
			arr[j][1] = ft_atoi(r[2]);
		}
		free_array(r, map, 0);
	}
	i = -1;
	while (++i < map->rooms_count)
	{
		j = i - 1;
		while (++j < map->rooms_count)
			if (arr[i][i] == arr[i][j])
				free_map(map, 1);
	}
}
