/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_intersections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:06:28 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/20 19:17:00 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int			point_to_one_another(t_map *map, int key, int data)
{
	t_adj_list_node		*tmp;

	tmp = map->graph[data].head;
	while (tmp)
	{
		if (tmp->data == key)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void			del_node(t_adj_list_node **head, int key)
{
	t_adj_list_node	*tmp;
	t_adj_list_node	*prev;
	int				code = 0;

	tmp = *head;
	prev = tmp;
	while (tmp && tmp->data != key)
	{
		prev = tmp;
		tmp = tmp->next;
		++code;
	}
	if (tmp->data == key)
	{
		if (code)
			prev->next = tmp->next;
		else
			*head = tmp->next;
		ft_memdel((void**)&tmp);
	}
}

void				delete_intersections(t_map *map)
{
	int				i;
	t_adj_list_node	*tmp;

	i = -1;
	while (++i < map->rooms_count)
	{
		tmp = map->graph[i].head;
		while (tmp)
		{
			if (point_to_one_another(map, i, tmp->data))
			{
				del_node(&map->graph[tmp->data].head, i);
				del_node(&map->graph[i].head, tmp->data);
			}
			tmp = tmp->next;
		}
	}
}
