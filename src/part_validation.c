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

int		g_start = 0;
int		g_end = 0;

void		check_links_start_end(t_map *map)
{
	int		i;
	int		code_e;
	int		code_s;

	i = -1;
	code_s = 0;
	code_e = 0;
	while (++i < map->rooms_count)
	{
		if (map->matrix[0][i] == 1)
			code_s++;
		if (map->matrix[map->rooms_count - 1][i] == 1)
			code_e++;
	}
	if (!code_s || !code_e)
		free_map(map, 1);
}

void		start_end_val(char **r)
{
	if (ft_strcmp(r[0], "##start") == 0)
		g_start++;
	if (ft_strcmp(r[0], "##end") == 0)
		g_end++;
}

void		part_validation_map(t_map *map)
{
	int		i;
	char	**line;
	char	**r;

	i = -1;
	line = ft_strsplit(map->in->rooms_list, '\n');
	while (line[++i])
	{
		r = ft_strsplit(line[i], ' ');
		start_end_val(r);
		free_array(r, map, 0);
	}
	if (g_start > 1 || g_end > 1 || !g_start || !g_end)
		free_array(line, map, 1);
	free_array(line, map, 0);
	part_validation_map_2(map);
	check_links_start_end(map);
}

void		part_validation_map_2(t_map *map)
{
	int		i;
	int		start;
	int		end;

	i = -1;
	start = 0;
	end = 0;
	while (++i < map->rooms_count)
	{
		if (map->matrix[0][i] == 1)
			start++;
		if (map->matrix[map->rooms_count - 1][i] == 1)
			end++;
	}
	if (start == 0 || end == 0)
		free_map(map, 1);
}
