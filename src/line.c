/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:27:22 by ksoedama          #+#    #+#             */
/*   Updated: 2025/02/12 18:26:45 by ksoedama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	window_limit(mlx_image_t *img, t_3d_points start)
{
	if (start.pos.x >= 0 && start.pos.y >= 0 && start.pos.x < img->width
		&& start.pos.y < img->height)
		mlx_put_pixel(img, start.pos.x, start.pos.y, start.color);
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
	while (start.pos.x++ <= end.pos.x)
	{
		window_limit(img, start);
		if (d > 0)
		{
			start.pos.y += yi;
			d += (2 * (dy - dx));
		}
		else
			d += 2 * dy;
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
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	d = (2 * dx) - dy;
	while (start.pos.y++ <= end.pos.y)
	{
		window_limit(img, start);
		if (d > 0)
		{
			start.pos.x += xi;
			d += (2 * (dx - dy));
		}
		else
			d += 2 * dx;
	}
}

void	draw_line(mlx_image_t *img, t_3d_points start, t_3d_points end)
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
