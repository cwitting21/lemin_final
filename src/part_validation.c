/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:52:35 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/27 22:34:36 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		start = 0;
int		end = 0;

void		start_end_val(char **r)
{
	if (ft_strcmp(r[0], "##start") == 0)
		start++;
	if (ft_strcmp(r[0], "##end") == 0)
		end++;
}

void		part_validation_map(t_map *map)
{
	int		i;
	char	**line;
	char	**r;
	// char	**arr;

	i = -1;
	line = ft_strsplit(map->in->rooms_list, '\n');
	while (line[++i])
	{
		r = ft_strsplit(line[i], ' ');
		start_end_val(r);
		free_array(r, map, 0);
	}
	if (start > 1 || end > 1 || !start || !end)
		free_array(line, map, 1);
	free_array(line, map, 0);
	part_validation_map_2(map);
}

void		part_validation_map_2(t_map *map)
{
	int		i;
	int		start;
	int 	end;

	i = -1;
	start = 0;
	end = 0;
	while (++i < map->rooms_count)
	{
		if (map->matrix[0][i] == 1)
			start++;
		if (map->matrix[map->rooms_count -1][i] == 1)
			end++;
	}
	if (start == 0 || end == 0)
		free_map(map, 1);
}
