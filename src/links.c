/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 19:35:18 by fculator          #+#    #+#             */
/*   Updated: 2020/01/15 18:37:57 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			add_link_list(t_map *map, char *line)
{
	map->val->part == 2 ? map->val->part = 3 : 0;
	if (map->val->part != 3)
		free_map(map, 1);
	map->in->link_list = ft_join(map->in->link_list, line, 0);
}

void	validate_link(t_map *map, char *link)
{
	char **l;

	l = ft_strsplit(link, '-');
	if (l[2] != NULL)
		free_array(l, map, 1);
	free_array(l, map, 0);
}

