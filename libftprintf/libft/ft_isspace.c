/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:19:45 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/28 16:19:47 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

int		ft_isblank(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' \
			|| c == '\v' || c == '\r' || c == '\f')
		return (1);
	return (0);
}
