/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_adj_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 23:49:17 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/18 22:17:02 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		print_adj_list(t_map *map)
{
	int			i = -1;
	t_adj_list_node	*tmp;

	printf("ADJ LIST\n\n");
	while (++i < map->rooms_count)
	{
		printf("[%s-%d] :", map->rooms[i], i);
		tmp = map->array[i].head;
		while (tmp)
		{
			printf(" %s ", map->rooms[tmp->data]);
			tmp = tmp->next;
		}
		printf("\n");
	}
}
