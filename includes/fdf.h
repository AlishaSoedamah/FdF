/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:24:58 by ksoedama          #+#    #+#             */
/*   Updated: 2025/02/10 14:24:41 by ksoedama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "MLX42/MLX42.h"
# include "libft.h"
# include "vector.h"
# include <fcntl.h>
# include <math.h>

# define WIDTH 1920
# define HEIGHT 1080

# define PI 3.14159265359
# define SQRT2 1.41421356237309514547
# define SQRT6 2.44948974278317788134

# define TILEZOOM 10
# define ANGLE 40

# define SUCCESS 1
# define FAILURE 0

typedef struct s_3d_points
{
	t_vect_3	pos;
	int			color;
}				t_3d_points;

typedef struct s_map
{
	int			width;
	int			height;
	t_3d_points	*map;
	t_vect_3	position;
	t_vect_3	angles;
}				t_map;

typedef struct s_fdf
{
	mlx_t		*mlx_ptr;
	mlx_image_t	*img;
	t_map		map;
	int			is_draw;
}				t_fdf;

int				check_name(char **av);
int				get_map_size(t_map *map, char *filename);
int				parse_file(t_map *map, char *filename);
void			draw_line(mlx_image_t *img, t_3d_points start, t_3d_points end);
void			draw_map(mlx_image_t *img, t_map *map);
void			my_keyhook(mlx_key_data_t keydata, void *param);
void			zoom(t_map *map);
t_3d_points		rotate_xyz(t_3d_points pointer, t_vect_3 angle);

#endif
