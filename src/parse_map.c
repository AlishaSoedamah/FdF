/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:38:42 by ksoedama          #+#    #+#             */
/*   Updated: 2025/02/16 12:08:59 by ksoedama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <limits.h>

static int	get_color(t_map *map, char **color_point, int x, int y)
{
	char	*endptr;
	int		is_overflow;
	int		color;

	is_overflow = 0;
	if (color_point[1] != NULL)
	{
		if (ft_strlen(color_point[1]) > 9)
			return (ft_free(color_point), FAILURE);
		color = ft_strtol(color_point[1], &endptr, &is_overflow, 16);
		if (color < 0 || color > INT_MAX || is_overflow || *endptr != '\0')
			return (ft_free(color_point), FAILURE);
		map->map[y * map->width + x].color = ((long)color << 8) | 0x000000FF;
	}
	else
		map->map[y * map->width + x].color = 0xFFFFFFFF;
	return (SUCCESS);
}

static int	parse_z_coordinate(char *str, double *z)
{
	char	*endptr;
	int		is_overflow;
	long	tmp;

	is_overflow = 0;
	tmp = ft_strtol(str, &endptr, &is_overflow, 10);
	if (*endptr != '\0' || is_overflow || tmp < MAP_MIN || tmp > MAP_MAX)
		return (1);
	*z = (double)tmp * TILEZOOM_Z;
	return (0);
}

static int	get_info(char *line, t_map *map)
{
	int			x;
	static int	y;
	char		**array;
	char		**point;

	array = ft_split(line, ' ');
	if (!array)
		return (FAILURE);
	x = 0;
	while (x < map->width)
	{
		point = ft_split(array[x], ',');
		if (!point)
			return (ft_free(array), FAILURE);
		map->map[y * map->width + x].pos.x = x * TILEZOOM;
		map->map[y * map->width + x].pos.y = y * TILEZOOM;
		if (parse_z_coordinate(point[0], &map->map[y * map->width + x].pos.z))
			return (ft_free(array), ft_free(point), FAILURE);
		if (get_color(map, point, x, y) == FAILURE)
			return (ft_free(array), ft_free(point), FAILURE);
		x++;
		ft_free(point);
	}
	y++;
	return (ft_free(array), SUCCESS);
}

static void	center_map(t_map *map)
{
	int			x;
	int			y;
	t_vect_3	center;

	center = vec_3(map->width / 2 * TILEZOOM, map->height / 2 * TILEZOOM, 0);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->map[y * map->width + x].pos = vec_3_sub(map->map[y * map->width
					+ x].pos, center);
			x++;
		}
		y++;
	}
}

int	parse_file(t_map *map, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Map doesn't exist or has wrong permissions\n", 2),
			FAILURE);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_strchr(line, '\n'))
			*ft_strchr(line, '\n') = '\0';
		if (get_info(line, map) == FAILURE)
		{
			free(line);
			close(fd);
			return (FAILURE);
		}
		free(line);
	}
	close(fd);
	center_map(map);
	return (SUCCESS);
}
