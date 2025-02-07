/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:27:22 by ksoedama          #+#    #+#             */
/*   Updated: 2025/02/07 17:53:16 by ksoedama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdlib.h>

static t_3d_points	map_get(t_map *map, int x, int y)
{
	return (map->map[y * map->width + x]);
}

static void	horizontal_line(mlx_image_t *img, t_3d_points start,
		t_3d_points end)
{
	int	dx;
	int	dy;
	int	yi;
	int	d;

	dx = end.pos.x - start.pos.x;
	dy = end.pos.y - start.pos.y;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	d = (2 * dy) - dx;
	while (start.pos.x < end.pos.x)
	{
		if (start.pos.x >= 0 && start.pos.y >= 0 && start.pos.x < img->width
			&& start.pos.y < img->height)
			mlx_put_pixel(img, start.pos.x, start.pos.y, start.color);
		if (d > 0)
		{
			start.pos.y += yi;
			d += (2 * (dy - dx));
		}
		else
			d += 2 * dy;
		start.pos.x++;
	}
}

static void	vertical_line(mlx_image_t *img, t_3d_points start, t_3d_points end)
{
	int	dx;
	int	dy;
	int	xi;
	int	d;

	dx = end.pos.x - start.pos.x;
	dy = end.pos.y - start.pos.y;
	xi = 1;
	if (dy < 0)
	{
		xi = -1;
		dx = -dx;
	}
	d = (2 * dx) - dy;
	while (start.pos.y < end.pos.y)
	{
		if (start.pos.x >= 0 && start.pos.y >= 0 && start.pos.x < img->width
			&& start.pos.y < img->height)
			mlx_put_pixel(img, start.pos.x, start.pos.y, start.color);
		if (d > 0)
		{
			start.pos.x += xi;
			d += (2 * (dx - dy));
		}
		else
			d += 2 * dx;
		start.pos.y++;
	}
}

static void	draw_line(mlx_image_t *img, t_3d_points start, t_3d_points end)
{
	if (fabs(end.pos.y - start.pos.y) < fabs(end.pos.x - start.pos.x))
	{
		if (start.pos.x > end.pos.x)
			horizontal_line(img, end, start);
		else
			horizontal_line(img, start, end);
	}
	else
	{
		if (start.pos.y > end.pos.y)
			vertical_line(img, end, start);
		else
			vertical_line(img, start, end);
	}
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
			// start = isometric(start, img->width, img->height);
			start.pos = vec_3_add(start.pos, map->position);
			if (x < map->width - 1)
			{
				end = map_get(map, x + 1, y);
				end = rotate_xyz(end, map->angles);
				// end = isometric(end, img->width, img->height);
				end.pos = vec_3_add(end.pos, map->position);
				draw_line(img, start, end);
			}
			if (y < map->height - 1)
			{
				end = map_get(map, x, y + 1);
				end = rotate_xyz(end, map->angles);
				// end = isometric(end, img->width, img->height);
				end.pos = vec_3_add(end.pos, map->position);
				draw_line(img, start, end);
			}
			x++;
		}
		y++;
	}
}

// this needs to be done so big maps dont segfault
// void	draw_map(mlx_image_t *img, t_map *map)
// {
// 	int			chunc_x;
// 	int			chunc_y;
// 	int			y;
// 	int			x;
// 	t_3d_points	end;
// 	t_3d_points	start;

// 	chunc_x = 0;
// 	chunc_y = 0;
// 	while (y < map->height)
// 	{
// 		x = 0;
// 		while (x < map->width)
// 		{
// 			start = map_get(map, x, y);
// 			start = rotate_xyz(start, map->angles);
// 			start.pos = vec_3_add(start.pos, map->position);
// 			if (x < map->width - 1)
// 			{
// 				end = map_get(map, x + 1, y);
// 				end = rotate_xyz(end, map->angles);
// 				end.pos = vec_3_add(end.pos, map->position);
// 				draw_line(img, start, end);
// 			}
// 			if (y < map->height - 1)
// 			{
// 				end = map_get(map, x, y + 1);
// 				end = rotate_xyz(end, map->angles);
// 				end.pos = vec_3_add(end.pos, map->position);
// 				draw_line(img, start, end);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	draw_map(mlx_image_t *img, t_map *map)
// {
// 	int y;
// 	int x;
// 	t_3d_points end;
// 	t_3d_points start;

// 	y = 0;
// 	while (y < map->height)
// 	{
// 		x = 0;
// 		while (x < map->width)
// 		{
// 			start = map_get(map, x, y);
// 			if (x < map->width - 1)
// 			{
// 				end = map_get(map, x + 1, y);
// 				draw_line(img, perspective(start, img->width, img->height),
// 					perspective(end, img->width, img->height));
// 			}
// 			if (y < map->height - 1)
// 			{
// 				end = map_get(map, x, y + 1);
// 				draw_line(img, perspective(start, img->width, img->height),
// 					perspective(end, img->width, img->height));
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }