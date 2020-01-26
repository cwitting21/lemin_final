/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_graph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:11:09 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/20 19:11:39 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		print_graph(t_map *map)
{
	int			i = -1;
	t_adj_list_node	*tmp;
	t_adj_list_node	*tmp2;

	printf("\n\nGRAPH\n\n");
	while (++i < map->rooms_count)
	{
		tmp = map->graph[i].head;
		tmp2 = tmp;
		if (tmp)
			printf("[%s] :", map->rooms[i]);
		while (tmp)
		{
			printf(" %s ", map->rooms[tmp->data]);
			tmp = tmp->next;
		}
		if (tmp2)
			printf("\n");
	}
}