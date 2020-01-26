/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ways_to_graph.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 06:11:13 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/19 07:33:28 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		test_print(t_map *map)
{
	int			i = -1;
	t_adj_list_node	*tmp;
	t_adj_list_node	*tmp2;

	printf("\n\nGRAPH\n\n");
	while (++i < map->rooms_count)
	{
		tmp = map->graph[i].head;
		tmp2 = tmp;
		if (tmp)
			printf("[%s] :", map->rooms[i]);
		while (tmp)
		{
			printf(" %s ", map->rooms[tmp->data]);
			tmp = tmp->next;
		}
		if (tmp2)
			printf("\n");
	}
}

static void			create_node(t_map *map, int from, int to)
{
	t_adj_list_node	*new;

	if (!(new = (t_adj_list_node*)ft_memalloc(sizeof(t_adj_list_node))))
		exit(1);
	new->data = to;
	new->next = map->graph[from].head;
	map->graph[from].head = new;
}

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

void				add_ways_to_graph(t_map *map)
{
	int				i;
	int				k;
	t_adj_list_node	*tmp;

	i = -1;
	if (!(map->graph = (t_adj_list*)ft_memalloc(map->rooms_count * sizeof(t_adj_list))))
		exit(1);
	while (++i < map->ways->n) // creating a new graph
	{
		k = -1;
		while (++k < map->rooms_count)
		{
			tmp = map->ways[i].way[k].head;
			if (tmp)
				create_node(map, k, tmp->data);
		}
	}
	test_print(map);
	printf("\n");
	i = -1;
	while (++i < map->rooms_count) // deleting edges if 2 vertices point to one another
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
	test_print(map);
}
