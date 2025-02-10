/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:56:32 by ksoedama          #+#    #+#             */
/*   Updated: 2025/02/10 13:29:25 by ksoedama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	key_rotate(mlx_key_data_t keydata, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	(void)keydata;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_REPEAT)
	{
		fdf->map.angles.y -= 0.05;
		ft_bzero(fdf->img->pixels, fdf->img->width * fdf->img->height
			* sizeof(int));
	}
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_REPEAT)
	{
		fdf->map.angles.y += 0.05;
		ft_bzero(fdf->img->pixels, fdf->img->width * fdf->img->height
			* sizeof(int));
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	(void)keydata;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(fdf->mlx_ptr);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_REPEAT)
	{
		fdf->map.angles.z += 0.05;
		ft_bzero(fdf->img->pixels, fdf->img->width * fdf->img->height
			* sizeof(int));
	}
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_REPEAT)
	{
		fdf->map.angles.x += 0.05;
		ft_bzero(fdf->img->pixels, fdf->img->width * fdf->img->height
			* sizeof(int));
	}
	key_rotate(keydata, param);
	fdf->is_draw = 1;
}
