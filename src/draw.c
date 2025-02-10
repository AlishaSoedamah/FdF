/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:18:23 by ksoedama          #+#    #+#             */
/*   Updated: 2025/02/10 14:35:11 by ksoedama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_3d_points	map_get(t_map *map, int x, int y)
{
	return (map->map[y * map->width + x]);
}

void	draw_map(mlx_image_t *img, t_map *map)
{
	int			y;
	int			x;
	t_3d_points	end;
	t_3d_points	start;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			start = map_get(map, x, y);
			start = rotate_xyz(start, map->angles);
			start.pos = vec_3_add(start.pos, map->position);
			if (x < map->width - 1)
			{
				end = map_get(map, x + 1, y);
				end = rotate_xyz(end, map->angles);
				end.pos = vec_3_add(end.pos, map->position);
				draw_line(img, start, end);
			}
			if (y < map->height - 1)
			{
				end = map_get(map, x, y + 1);
				end = rotate_xyz(end, map->angles);
				end.pos = vec_3_add(end.pos, map->position);
				draw_line(img, start, end);
			}
			x++;
		}
		y++;
	}
}
