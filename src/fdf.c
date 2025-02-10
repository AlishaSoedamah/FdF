/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:39:51 by ksoedama          #+#    #+#             */
/*   Updated: 2025/02/10 14:26:25 by ksoedama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_map(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->map = NULL;
	map->position = vec_3(0, 0, 10);
	map->angles = vec_3(0, 0, 0);
}

static void	hook_resize(int32_t width, int32_t height, void *param)
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

static void	make_fdf(t_fdf fdf)
{
	fdf.map.position = vec_3(WIDTH / 2, HEIGHT / 2, 0);
	fdf.mlx_ptr = mlx_init(WIDTH, HEIGHT, "FdF ✨", true);
	fdf.img = mlx_new_image(fdf.mlx_ptr, WIDTH, HEIGHT);
	mlx_image_to_window(fdf.mlx_ptr, fdf.img, 0, 0);
	mlx_key_hook(fdf.mlx_ptr, &my_keyhook, &fdf);
	mlx_resize_hook(fdf.mlx_ptr, hook_resize, &fdf);
	mlx_loop_hook(fdf.mlx_ptr, hook_loop, &fdf);
	mlx_loop(fdf.mlx_ptr);
	mlx_delete_image(fdf.mlx_ptr, fdf.img);
	mlx_close_window(fdf.mlx_ptr);
	mlx_terminate(fdf.mlx_ptr);
}

int	main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac <= 1 || ac > 2)
		return (ft_putstr_fd("Usage: ./fdf [map.fdf]\n", 2), FAILURE);
	if (ac == 2)
	{
		if (check_name(av))
			return (ft_putstr_fd("Usage: ./fdf [map.fdf]\n", 2), FAILURE);
		fdf.is_draw = 1;
		init_map(&fdf.map);
		if (get_map_size(&fdf.map, av[1]) == FAILURE)
			return (ft_putstr_fd("Can't get map size\n", 2), FAILURE);
		if (parse_file(&fdf.map, av[1]))
			make_fdf(fdf);
		free(fdf.map.map);
	}
	return (0);
}
