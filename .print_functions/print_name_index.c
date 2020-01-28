/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_name_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 03:11:45 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/28 08:54:17 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void				print_name_index(t_map *map)
{
	int				i;
	int				c;
	t_al_node		*tmp;

	i = -1;
	c = 0;
	ft_printf("\n--------------------\n\n      MAP ROOMS\n\n");
	while (++i < map->rooms_count)
		ft_printf("name = %s  ...  i = %d\n", map->rooms[i], i);
	ft_printf("\n--------------------\n\n      MAP WAYS\n\n");
	i = -1;
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
				printf("  ...  i = %d\n", i);
				c++;
			}
		}
	}
	printf("\n%d Lines\n--------------------\n", c);
}
