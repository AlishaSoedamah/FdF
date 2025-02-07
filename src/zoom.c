/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:30:42 by ksoedama          #+#    #+#             */
/*   Updated: 2025/02/07 10:28:33 by ksoedama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
void zoom(t_map *map)
{
	int y;
	int x;

	y = 0;
	while (y <= map->width)
	{
		x = 0;
		while (x < map->width)
		{
			map->map[y * map->width + x].pos.x = x * TILEZOOM;
			map->map[y * map->width + x].pos.y = y * TILEZOOM;
			x++;
		}
		y++;
	}
}