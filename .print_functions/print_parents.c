/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parents.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 00:32:56 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/28 08:56:08 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		print_parents(t_map *map, int *parent)
{
	int		b;

	b = -1;
	ft_printf("\nPARENTS:\n\n");
	while (++b < map->rooms_count)
		ft_printf("room->[%s] = parent->%s\n", map->rooms[b], map->rooms[parent[b]]);
}
