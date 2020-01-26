/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connectivity_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:10:04 by fculator          #+#    #+#             */
/*   Updated: 2020/01/21 18:51:15 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		connectivity_matrix(t_map *map)
{
	int		i;
	int		r_1;
	int		r_2;
	char	**l;
	char	**links;

	i = -1;
	links = ft_strsplit(map->in->link_list, '\n');
	while (links[++i])
	{
		if (links[i][0] == '#' && !(!ft_strcmp(links[i], "##start") || !ft_strcmp(links[i], "##end")))
			continue ;
		validate_link(map, links[i]);
		l = ft_strsplit(links[i], '-');
		if ((r_1 = room_index(map, l[0], 1)) >= map->rooms_count ||
			(r_2 = room_index(map, l[1], 1)) >= map->rooms_count)
		{
			free_array(l, map, 0);
			free_array(links, map, 1);
		}
		map->matrix[r_1][r_2] = 1;
		map->matrix[r_2][r_1] = 1;
		free_array(l, map, 0);
	}
	free_array(links, map, 0);
}
