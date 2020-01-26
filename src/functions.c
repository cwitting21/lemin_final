/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 16:59:33 by fculator          #+#    #+#             */
/*   Updated: 2020/01/11 21:24:23 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			is_empty(char *s)
{
	size_t i;

	i = 0;
	while (s[i] && (s[i] == ' '))
		i++;
	if (i == ft_strlen(s))
		return (1);
	return (0);
}

void	is_number(char **r, t_map *map, char *s)
{
	int i;

	i = 0;
	if (s[0] == '-' || ft_isdigit(s[0]))
	{
		while (s[++i])
		{
			if (!ft_isdigit(s[i]))
				free_array(r, map, 1);
		}
	}
	else
		free_array(r, map, 1);
}

void	free_array(char **array, t_map *map, int code)
{
	int i;

	i = 0;
	while (array[i])
		(array[i]) ? free(array[i++]) : 0;
	if (array && *array)
		free(array);
	if (code && map)
		free_map(map, 1);
	array = NULL;
}

void	good(t_map *map, char **line, char **r, int end)
{
	if (++(map->val->good[end]) > 1)
	{
		free_array(r, map, 0);
		free_array(line, map, 1);
	}
}

void	check_start_end(t_map *map, char **r, int end)
{
	if (end)
	{
		map->rooms[map->rooms_count - 1] = ft_strdup(r[0]);
		(map->val->good[1])++;
		return ;
	}
	map->rooms[0] = ft_strdup(r[0]);
	(map->val->good[0])++;
}