/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 07:52:21 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/27 20:52:13 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		free_all(t_map *map)
{
	int		i;
	int		k;
	t_al_node	*tmp;
	t_al_node	*del;

	i = -1;
	while (++i < map->rooms_count)
		ft_memdel((void**)&map->matrix[i]);
	ft_memdel((void**)&map->matrix);
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
	ft_memdel((void**)&map->array);
	i = -1;
	while (++i < map->rooms_count)
		ft_memdel((void**)&map->rooms[i]);
	ft_memdel((void**)&map->rooms);
	ft_memdel((void**)&map->in->ants_list);
	ft_memdel((void**)&map->in->link_list);
	ft_memdel((void**)&map->in->rooms_list);
	ft_memdel((void**)&map->in);
	ft_memdel((void**)&map->val);
	ft_memdel((void**)&map->val);
	ft_memdel((void**)&map->in_way);
	// free graph
	i = -1;
	while (++i < map->rooms_count)
	{
		tmp = map->graph[i].head;
		while (tmp)
		{
			del = tmp;
			tmp = tmp->next;
			ft_memdel((void**)&del);
		}
	}
	// free ways
	i = -1;
	while (++i < map->ways->n)
	{
		k = -1;
		while (++k < map->rooms_count)
		{
			tmp = map->ways[i].way[k].head;
			while (tmp)
			{
				del = tmp;
				tmp = tmp->next;
				ft_memdel((void**)&del);
			}
		}
		ft_memdel((void**)&map->ways[i].way);
	}
	// i = -1;
	// int k;
	// while (++i < map->r_ways->n)
	// {
	// 	k = -1;
	// 	while (++k < map->rooms_count)
	// 	{
	// 		tmp = map->r_ways[i].way[k].head;
	// 		while (tmp)
	// 		{
	// 			del = tmp;
	// 			tmp = tmp->next;
	// 			ft_memdel((void**)&del);
	// 		}
	// 	}
	// 	ft_memdel((void**)&map->r_ways[i].way);
	// }
	// ft_memdel((void**)&map->r_ways);
	ft_memdel((void**)&map->graph);
	ft_memdel((void**)&map->ways);
	ft_memdel((void**)&map);
}