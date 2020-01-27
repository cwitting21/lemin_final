/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_name_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 03:11:45 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/27 20:52:13 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void				print_name_index(t_map *map)
{
	int				i;
	t_al_node	*tmp;

	i = -1;
	printf("\n");
	printf("--------------------\n");
	printf("\n");
	printf("      MAP ROOMS\n");
	printf("\n");
	while (++i < map->rooms_count)
	{
		printf("name = %s  ...  ", map->rooms[i]);
		printf("i = %d\n", i);
	}
	printf("\n");
	printf("--------------------\n");
	printf("\n");
	printf("      MAP WAYS\n");
	printf("\n");
	i = -1;
	int c = 0;
	while (++i < map->rooms_count)
	{
		tmp = map->ways[0].way[i].head;
		if (tmp)
			printf("[%s] :", map->rooms[i]);
		while (tmp)
		{
			printf(" %s ", map->rooms[tmp->data]);
			tmp = tmp->next;
			if (!tmp)
			{
				printf("  ...  i = %d", i);
				c++;
				printf("\n");
			}
		}
	}
	printf("\n");
	printf("%d Lines\n", c);
	printf("--------------------\n");
}
