/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connectivity_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:10:04 by fculator          #+#    #+#             */
/*   Updated: 2020/01/27 22:42:50 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
**	r[0] - r1
**	r[1] - r2
*/

void		connectivity_matrix(t_map *map)
{
	int		i;
	int		r[2];
	char	**l;
	char	**links;

	i = -1;
	links = ft_strsplit(map->in->link_list, '\n');
	while (links[++i])
	{
		if (links[i][0] == '#' && !(!ft_strcmp(links[i], "##start") ||
			!ft_strcmp(links[i], "##end")))
			continue ;
		validate_link(map, links[i]);
		l = ft_strsplit(links[i], '-');
		if ((r[0] = room_index(map, l[0], 1)) >= map->rooms_count ||
			(r[1] = room_index(map, l[1], 1)) >= map->rooms_count)
		{
			free_array(l, map, 0);
			free_array(links, map, 1);
		}
		map->matrix[r[0]][r[1]] = 1;
		map->matrix[r[1]][r[0]] = 1;
		free_array(l, map, 0);
	}
	free_array(links, map, 0);
}
