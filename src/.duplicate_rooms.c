/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .duplicate_rooms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 03:02:28 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/27 20:52:13 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			create_node(int data, t_al_node **from)
{
	t_al_node	*new;

	if (!(new = (t_al_node*)ft_memalloc(sizeof(t_al_node))))
		exit(1);
	new->data = data;
	new->next = *from;
	*from = new;
}

static int			to_regular_room(int *arr, int key)
{
	int				i;

	i = -1;
	while (arr[++i])
	{
		if (arr[i] == key)
			return (0);
	}
	return (1);
}

static int			to_room_to_dup2(int *arr, int key)
{
	int				i;

	i = -1;
	while (arr[++i])
	{
		if (arr[i] == key)
			return (1);
	}
	return (0);
}

static void			create_in_to_out(t_al_node **from, int data)
{
	t_al_node	*new;

	if (!(new = (t_al_node*)ft_memalloc(sizeof(t_al_node))))
		exit(1);
	new->data = data;
	new->next = *from;
	*from = new;
}

static void			duplicate_one_room(int index, t_map *map, int *arr)
{
	t_al_node	*tmp;

	tmp = map->array[index].head;
	create_in_to_out(&map->array[index].in, index);
	map->dup_arr[index] = True;
	while (tmp)
	{
		if (tmp->data == 0)
			create_node(tmp->data, &map->array[index].in);
		else if (to_regular_room(arr, tmp->data))
			create_node(tmp->data, &map->array[index].out);
		else if (to_room_to_dup2(arr, index))
			create_node(tmp->data, &map->array[index].in);
		tmp = tmp->next;
	}
}

static int			get_index_in_m_array(int key, t_map *map)
{
	t_al_node	*tmp;
	int				i;

	i = -1;
	while (++i < map->rooms_count)
	{
		tmp = map->ways[0].way[i].head;
		while (tmp)
		{
			if (tmp->data == key)
				return (tmp->data);
			tmp = tmp->next;
		}
	}
	return (0);
}

static int			room_to_dup1(int key, t_map *map)
{
	t_al_node	*tmp;
	int				i;

	i = -1;
	while (++i < map->rooms_count)
	{
		tmp = map->ways[0].way[i].head;
		while (tmp)
		{
			if (tmp->data == key)
				return (1);
			tmp = tmp->next;
		}
	}
	return (0);
}

static int			is_dup(int i, t_bool *arr)
{
	if (arr[i])
		return (1);
	return (0);
}

static int			from_rr(t_bool *arr, int i)
{
	if (arr[i])
		return (0);
	return (1);
}

static int			to_rtd(t_bool *arr, int i)
{
	if (arr[i])
		return (1);
	return (0);
	
}

void				duplicate_rooms(t_map *map)
{
	int				arr[map->rooms_count]; // array of room indexes at map->array that need to be reversed
	int				arr_i;
	int				i;
	t_al_node	*tmp;
	t_al_node	*tmp_in;
	t_al_node	*tmp_out;
	int				index = 0;

	arr_i = 0;
	ft_bzero(arr, map->rooms_count * sizeof(int));
	i = -1;
	while (++i < map->rooms_count)
	{
		tmp = map->ways[0].way[i].head;
		if (tmp)
		{
			if (i != 0 && i != map->rooms_count - 1)
			arr[arr_i++] = i;
		}
	}
	printf("\nARR:\n");
	for (int i = 0; i < map->rooms_count; i++)
		printf("[%d]-%d ", i, arr[i]);
	printf("\n\n");
	i = -1;
	while (++i < map->rooms_count)
	{
		if (room_to_dup1(arr[i], map))
		{
			index = get_index_in_m_array(arr[i], map);
			duplicate_one_room(index, map, arr);
		}
	}
	i = -1;
	// test print
	while (++i < map->rooms_count)
	{
		tmp_in = map->array[i].in;
		tmp_out = map->array[i].out;
		if (tmp_in)
		{
			while (tmp_in)
			{
				if (i == tmp_in->data)
					printf("from [%d]-out to [%d]-in\n", i, tmp_in->data);
				else if (is_dup(i, map->dup_arr) && is_dup(tmp_in->data, map->dup_arr))
					printf("from [%d]-in to [%d]-out\n", i, tmp_in->data);
				else
					printf("from [%d]-in to [%d]\n", i, tmp_in->data);
				tmp_in = tmp_in->next;
			}
		}
		if (tmp_out)
		{
			while (tmp_out)
			{
				if (i == tmp_out->data)
					printf("from [%d]-out to [%d]-in\n", i, tmp_out->data);
				else
					printf("from [%d]-out to [%d]\n", i, tmp_out->data);
				tmp_out = tmp_out->next;
			}
		}
	}
	// printf("\nDuplicated rooms:\n");
	// for (int i = 0; i < 10000; i++)
	// 	if (map->dup_arr[i])
	// 		printf("i = %d\n", i);
	// printf("\n");
	// printf("%d rooms (all)\n", map->rooms_count);
//////////////////////////////////////////////////////////////////////////
	printf("\n");
	i = -1;
	while (++i < map->rooms_count)
	{
		tmp = map->array[i].head;
		while (tmp)
		{
			if (from_rr(map->dup_arr, i) && to_rtd(map->dup_arr, tmp->data)) // rr - regular room, rtd - room to duplicate
			{
				if (i != map->rooms_count - 1) // from end ro rtd
					printf("from [%d] to [%d]-in\n", i, tmp->data);
				else // from rr (!end) to rtd
					printf("from [end] to [%d]-out\n", tmp->data);
			}
			tmp = tmp->next;
		}
	}
	// bfs_2();
}
