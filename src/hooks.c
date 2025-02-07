/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:56:32 by ksoedama          #+#    #+#             */
/*   Updated: 2025/02/07 17:54:59 by ksoedama         ###   ########.fr       */
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
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_REPEAT)
	{
		fdf->map.angles.x -= 0.05;
		ft_bzero(fdf->img->pixels, fdf->img->width * fdf->img->height
			* sizeof(int));
	}
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_REPEAT)
	{
		fdf->map.angles.y += 0.05;
		ft_bzero(fdf->img->pixels, fdf->img->width * fdf->img->height
			* sizeof(int));
	}
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_REPEAT)
	{
		fdf->map.angles.z += 0.05;
		ft_bzero(fdf->img->pixels, fdf->img->width * fdf->img->height
			* sizeof(int));
	}
	fdf->is_draw = 1;
}
