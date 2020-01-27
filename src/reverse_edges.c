/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_edges.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:53:18 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/27 21:13:35 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		del_node(t_al_node **head, int key)
{
	t_al_node	*tmp;
	t_al_node	*prev;
	int			code;

	tmp = *head;
	prev = tmp;
	code = 0;
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
	t_al_node	*tmp1;
	t_al_node	*tmp2;
	t_al_node	*del;
	int			dst;
	int			i;

	i = -1;
	while (++i < map->rooms_count)
	{
		tmp1 = map->ways[way_i].way[i].head;
		while (tmp1)
		{
			dst = tmp1->data;
			tmp2 = map->array[i].head;
			while (tmp2)
			{
				del = tmp2;
				tmp2 = tmp2->next;
				if (del->data == dst)
					del_node(&map->array[i].head, del->data);
			}
			tmp1 = tmp1->next;
		}
	}
}
