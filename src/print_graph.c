/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_graph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:11:09 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/29 17:24:13 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			print_graph(t_map *map)
{
	int			i;
	t_al_node	*tmp;
	t_al_node	*tmp2;

	i = -1;
	ft_printf("\n\nGRAPH\n\n");
	while (++i < map->rooms_count)
	{
		tmp = map->graph[i].head;
		tmp2 = tmp;
		if (tmp)
			ft_printf("[%s] :", map->rooms[i]);
		while (tmp)
		{
			ft_printf(" %s ", map->rooms[tmp->data]);
			tmp = tmp->next;
		}
		if (tmp2)
			ft_printf("\n");
	}
}
