/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:56:32 by ksoedama          #+#    #+#             */
/*   Updated: 2025/02/15 13:25:08 by ksoedama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	(void)keydata;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(fdf->mlx_ptr);
}

void	hook_resize(int32_t width, int32_t height, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	mlx_resize_image(fdf->img, width, height);
	ft_bzero(fdf->img->pixels, width * height * sizeof(int));
	fdf->map.position = vec_3(fdf->img->width / 2, fdf->img->height / 2, 0);
	fdf->is_draw = 1;
}

void	hook_loop(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (fdf->is_draw)
	{
		draw_map(fdf->img, &fdf->map);
		fdf->is_draw = 1;
	}
}
