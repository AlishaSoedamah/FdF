/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:18:23 by ksoedama          #+#    #+#             */
/*   Updated: 2025/02/15 13:30:38 by ksoedama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_3d_points	map_get(t_map *map, int x, int y)
{
	return (map->map[y * map->width + x]);
}

static void	draw_map_inner(mlx_image_t *img, t_map *map, int x, int y)
{
	t_3d_points	end;
	t_3d_points	start;

	start = map_get(map, x, y);
	start = isometric(start);
	start.pos = vec_3_add(start.pos, map->position);
	if (x < map->width - 1)
	{
		end = map_get(map, x + 1, y);
		end = isometric(end);
		end.pos = vec_3_add(end.pos, map->position);
		draw_line(img, start, end);
	}
	if (y < map->height - 1)
	{
		end = map_get(map, x, y + 1);
		end = isometric(end);
		end.pos = vec_3_add(end.pos, map->position);
		draw_line(img, start, end);
	}
}

void	draw_map(mlx_image_t *img, t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			draw_map_inner(img, map, x, y);
			x++;
		}
		y++;
	}
}
