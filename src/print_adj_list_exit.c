/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_adj_list_exit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:33:26 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/29 18:10:40 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		free_exit(t_map *map)
{
	int			i;
	t_al_node	*tmp;
	t_al_node	*del;

	i = -1;
	while (++i < map->rooms_count)
	{
		tmp = map->array[i].head;
		while (tmp)
		{
			del = tmp;
			tmp = tmp->next;
			ft_memdel((void**)&del);
		}
	}
	i = -1;
	ft_memdel((void**)&map->array);
	free_map(map, 0);
	exit(EXIT_SUCCESS);
}

void			print_adj_list_exit(t_map *map)
{
	int			i;
	t_al_node	*tmp;

	i = -1;
	ft_printf("ADJ LIST\n\n");
	while (++i < map->rooms_count)
	{
		ft_printf("[%s-%d] :", map->rooms[i], i);
		tmp = map->array[i].head;
		while (tmp)
		{
			ft_printf(" %s ", map->rooms[tmp->data]);
			tmp = tmp->next;
		}
		ft_printf("\n");
	}
	free_exit(map);
}
