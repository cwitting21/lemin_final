/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 16:42:36 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/17 00:27:24 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		bfs(t_map *map)
{
	int		i = 0;
	int		k;
	int		visited[99999];
	int		parent[99999];
	int		count = 0;
	t_q		*q;

	ft_bzero(visited, 99999);
	ft_bzero(parent, 99999);
	q = (t_q*)ft_memalloc(sizeof(t_q));
	ft_bzero(q, sizeof(t_q));
	q->head = q->end = NULL;
	push_q(q, count); // add start node
	printf("LAST = %s\n", map->rooms[map->rooms_count - 1]);
	while (!empty_q(q) && i != map->rooms_count - 1)
	{
		i = pop_q(q);
		printf("%d\n", i);
		k = 0;
		while (k < map->rooms_count)
		{
			if (map->matrix[i][k] == 1 && !visited[k])
			{
				visited[k] = 1;
				push_q(q, k);
				parent[k] = i;
			}
			k++;
		}
	}
	printf("PARENT:\n");
	for (int b = 0; b < map->rooms_count; b++)
		printf("room->[%s] = parant->%s\n", map->rooms[b], map->rooms[parent[b]]);
	int a = parent[i];
	printf("------------\n");
	printf("%s\n", map->rooms[i]);
	while (a != 0)
	{
		printf("%s\n", map->rooms[a]);
		a = parent[a];
	}
	printf("%s\n", map->rooms[0]);
}