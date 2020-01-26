/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_shortest_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 00:53:42 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/17 00:56:26 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		print_shortest_path(t_map *map, int *parent, int i)
{
	int		a;

	a = parent[i];
	printf("the shortest path (end -> start):\n");
	printf("%s\n", map->rooms[i]);
	while (a != 0)
	{
		printf("%s\n", map->rooms[a]);
		a = parent[a];
	}
	printf("%s\n", map->rooms[0]);
}
