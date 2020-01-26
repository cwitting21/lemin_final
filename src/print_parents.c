/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parents.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 00:32:56 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/17 00:34:56 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		print_parents(t_map *map, int *parent)
{
	printf("\nPARENTS:\n\n");
	for (int b = 0; b < map->rooms_count; b++)
		printf("room->[%s] = parent->%s\n", map->rooms[b], map->rooms[parent[b]]);
}
