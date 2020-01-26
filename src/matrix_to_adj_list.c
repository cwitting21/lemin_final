/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_to_adj_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:16:24 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/26 22:21:27 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_adj_list_node	*create_node(t_map *map, int from, int to)
{
	t_adj_list_node	*new;

	if (!(new = (t_adj_list_node*)ft_memalloc(sizeof(t_adj_list_node))))
		return (NULL);
	new->data = to;
	new->next = map->array[from].head;
	map->array[from].head = new;
	return (new);
}

void		matrix_to_adj_list(t_map *map)
{
	int		i;
	int		j;

	i = -1;
	if (!(map->array = (t_adj_list*)ft_memalloc(map->rooms_count * sizeof(t_adj_list))))
		exit(1);
	while (++i < map->rooms_count)
	{
		j = -1;
		while (++j < map->rooms_count)
		{
			if (map->matrix[i][j] == 1)
			create_node(map, i, j);
		}
	}
}
