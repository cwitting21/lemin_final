/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_edges.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:53:18 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/27 01:20:31 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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

void			reverse_edges(t_map *map, int way_i)
{
	t_adj_list_node	*tmp1;
	t_adj_list_node	*tmp2;
	t_adj_list_node	*del;
	int		src1;
	int		dst1;
	int		i;

	i = -1;
	while (++i < map->rooms_count)
	{
		src1 = i;
		tmp1 = map->ways[way_i].way[i].head;
			while (tmp1)
			{
				dst1 = tmp1->data;
				tmp2 = map->array[i].head;
				while (tmp2)
				{
					del = tmp2;
					tmp2 = tmp2->next;
					if (del->data == dst1)
						del_node(&map->array[i].head, del->data);
				}
				tmp1 = tmp1->next;
			}
	}
}
