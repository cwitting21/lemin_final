/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .duplicate_rooms copy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 03:02:28 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/27 20:52:13 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// static t_al_node	*create_node(t_map *map, int i, int j)
// {
// 	t_al_node		*new;

// 	if (!(new = (t_al_node*)ft_memalloc(sizeof(t_al_node))))
// 		return (NULL);
// 	// new->visited = False;
// 	new->data = j;
// 	new->next = map->dup_arr[i].head;
// 	map->dup_arr[i].head = new;
// 	return (new);
// }

// static int	to_room_to_dup(int key, int *arr)
// {
	
// 	t_al_node	*tmp;
// 	int			i;

// 	i = -1;
// 	while (arr[++i] != 0)
// 	{
// 		if (arr[i] == key)
// 			return (1);
// 	}
// 	// while (++i < map->rooms_count)
// 	// {
// 	// 	tmp = map->ways[0].way[i].head;
// 	// 	while (tmp)
// 	// 	{
// 	// 		if (tmp->data == key)
// 	// 			return (1);
// 	// 		tmp = tmp->next;
// 	// 	}
// 	// }
// 	return (0);
// }

// static int		room_to_dup(int key, int *arr)
// {
// 	int			i;

// 	i = -1;
// 	while (arr[++i] != 0)
// 	{
// 		if (key == arr[i])
// 			return (1);
// 	}
// 	return (0);
// }

// // static int	from_room_to_dup(int key, t_map *map)
// // {
	
// // }

// void		duplicate_rooms(t_map *map)
// {
// 	int		i;
// 	t_al_node	*tmp;
// 	int		arr[10]; // array of room indexes at map->array that need to be duplicated
// 	int		arr_i = 0;

	// map->rooms_count += 0;
// 	ft_bzero(arr, 10 * 4);
// 	if (!(map->dup_arr = (t_al*)ft_memalloc(sizeof(t_al))))
// 		exit(1);
// 	i = -1;
// 	while (++i < map->rooms_count)
// 	{
// 		tmp = map->ways[0].way[i].head;
// 		if (tmp)
// 		{
// 			if (i != 0 && i != map->rooms_count - 1)
// 			arr[arr_i++] = i;
// 		}
// 	}
// 	printf("\nARR:\n");
// 	for (int i = 0; i < 10; i++)
// 	{
// 		printf("[%d]-%d ", i, arr[i]);
// 	}
// 	i = -1;
// 	// rtd == room to duplicate
// 	while (arr[++i] != 0)
// 	{
// 		tmp = map->array[arr[i]].head;
// 		while (tmp)
// 		{
// 			if (to_room_to_dup(tmp->data, arr) && arr[i] == map->rooms_count - 1) // from end to rtd
// 			// from end to rtd-(out)
// 			else if (to_room_to_dup(tmp->data, arr) && arr[i] != map->rooms_count - 1
// 			&& arr[i] != 0 && !room_to_dup(tmp->data, arr))
// 			// from !rtd to rtd-(in)
// 			else if (from_room_to_dup(arr[i], map))
// 			{
// 				if ()
// 				else if ()
// 			}
// 			else if () // from rtd to start
// 				//from rtd-(in) -> start

// 			tmp = tmp->next;
// 		}
// 		map->dup_arr[i * 2].head = create_node;
// 		map->dup_arr[i * 2 + 1].head = create_node;
// 	}
// }
