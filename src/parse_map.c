/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:38:42 by ksoedama          #+#    #+#             */
/*   Updated: 2025/02/10 14:16:21 by ksoedama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}

static void	get_color(t_map *map, char **color_point, int x, int y)
{
	if (color_point[1] != NULL)
		map->map[y * map->width + x].color = (ft_strtol(color_point[1], NULL,
					NULL, 16) << 8) | 0x000000FF;
	else
		map->map[y * map->width + x].color = 0xFFFFFFFF;
	ft_free(color_point);
}

static int	get_info(char *line, t_map *map)
{
	int			x;
	static int	y;
	char		**array;
	char		**color_point;

	if (line == NULL)
		return (FAILURE);
	if (ft_strchr(line, '\n'))
		*ft_strchr(line, '\n') = '\0';
	array = ft_split(line, ' ');
	x = -1;
	while (++x < map->width)
	{
		color_point = ft_split(array[x], ',');
		map->map[y * map->width + x].pos.x = x * TILEZOOM;
		map->map[y * map->width + x].pos.y = y * TILEZOOM;
		map->map[y * map->width + x].pos.z = ft_atoi(color_point[0]);
		get_color(map, color_point, x, y);
	}
	y++;
	ft_free(array);
	free(line);
	return (SUCCESS);
}

int	parse_file(t_map *map, char *filename)
{
	int			x;
	int			y;
	int			fd;
	t_vect_3	center;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Map doesn't exist or has wrong permissions\n", 2),
			FAILURE);
	while (get_info(get_next_line(fd), map) == SUCCESS)
		;
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
	return (SUCCESS);
}
