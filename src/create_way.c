/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_way.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 00:58:41 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/20 03:13:21 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		create_way(t_map *map, int i, int *parent, int way_i)
{
	int		a;

	a = parent[i];
	add_to_way(map->ways, a, i, way_i);
	while (a != 0)
	{
		add_to_way(map->ways, parent[a], a, way_i);
		a = parent[a];
	}
}
