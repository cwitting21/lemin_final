/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_adj_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 08:54:52 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/28 13:29:11 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		print_adj_list(t_map *map)
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
}
