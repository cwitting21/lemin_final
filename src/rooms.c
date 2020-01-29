/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 19:25:22 by fculator          #+#    #+#             */
/*   Updated: 2020/01/29 15:47:36 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	add_room_list(t_map *map, char *line)
{
	map->val->part = 2;
	map->in->rooms_list = ft_join(map->in->rooms_list, line, 0);
	if (line[0] == '#')
		return ;
	validate_room(map, line);
	map->rooms_count++;
}

void	validate_room(t_map *map, char *line)
{
	char **r;

	r = ft_strsplit(line, ' ');
	if (r[1] == NULL || r[2] == NULL)
		free_array(r, map, 1);
	if (r[0][0] == 'L' || r[3] != NULL)
		free_array(r, map, 1);
	is_number(r, map, r[1]);
	is_number(r, map, r[2]);
	free_array(r, map, 0);
}

int		room_index(t_map *map, char *room_name, int start)
{
	int index;

	index = (start) ? -1 : 0;
	while (map->rooms[++index] && index < map->rooms_count)
	{
		if (ft_strcmp(map->rooms[index], room_name) == 0)
			return (index);
	}
	return (index);
}

void	room_table(t_map *map)
{
	int		i;
	int		j;
	char	**line;
	char	**r;

	i = -1;
	j = 1;
	line = ft_strsplit(map->in->rooms_list, '\n');
	while (line[++i] && j < map->rooms_count)
	{
		r = ft_strsplit(line[i], ' ');
		if (!ft_strcmp("##start", line[i]))
			good(map, line, r, 0);
		else if (!ft_strcmp("##end", line[i]))
			good(map, line, r, 1);
		else if (map->val->good[0] == 1 && line[i][0] != '#')
			check_start_end(map, r, 0);
		else if (map->val->good[1] == 1 && line[i][0] != '#')
			check_start_end(map, r, 1);
		else if (line[i][0] != '#')
			is_valid(map, j++, r);
		free_array(r, map, 0);
	}
	free_array(line, map, 0);
}

void	is_valid(t_map *map, int i, char **r)
{
	int r_index;

	r_index = room_index(map, r[0], 0);
	if (r_index > 0 && i != r_index)
		free_map(map, 1);
	map->rooms[i] = ft_strdup(r[0]);
}
