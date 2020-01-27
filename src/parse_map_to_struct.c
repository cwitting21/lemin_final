/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_to_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:52:42 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/27 06:59:07 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	parse_map_to_struct(t_map *map)
{
	char	*line;

	// int fd = open("maps/invalid/test.txt", O_RDONLY);
	while (get_next_line(0, &line) > 0)
	{
		if (map->ants == 0)
			ants(map, line);
		else if (ft_strchr(line, '-') || map->val->part == 3)
			add_link_list(map, line);
		else if ((map->val->part == 1 || map->val->part == 2) && !is_empty(line))
			add_room_list(map, line);
		else
			free_map(map, 1);
	}
	if (map->ants == 0 || map->in->link_list[0] == '\0')
		free_map(map, 1);
}
