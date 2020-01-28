/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:52:35 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/28 15:06:01 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// RESTRUCTURE CODE MINDING ALL POSSIBLE ERRORS (malloc, ...)

int		main(int ac, char **av)
{
	t_map	*map;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		exit(EXIT_FAILURE);
	initialize_map(map);
	parse_map_to_struct(map);
	initialize_map_2(map);
	if (ac > 1)
		get_options(map, ac, av);
	check_coord(map);
	room_table(map);
	connectivity_matrix(map); // adj matrix created here?
	part_validation_map(map);
	matrix_to_adj_list(map);
	print_map(map);
	solve_map(map);
	free_all(map);
	exit(EXIT_SUCCESS);
}
