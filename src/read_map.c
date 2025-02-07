/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:27:18 by ksoedama          #+#    #+#             */
/*   Updated: 2025/02/07 16:46:31 by ksoedama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "fdf.h"
#include <fcntl.h>

static int	ft_count_points(char const *s, char c)
{
	unsigned int	i;
	int				counter;
	int				flag;

	i = 0;
	counter = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] != c && flag == 0)
		{
			flag = 1;
			counter++;
		}
		else if (s[i] == c)
			flag = 0;
		i++;
	}
	return (counter);
}

static void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}

void	init_map(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->map = NULL;
	map->position = vec_3(0, 0, 0);
	map->angles = vec_3(0, 0, 0);
}

int	get_map_size(t_map *map, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_strchr(line, '\n'))
			*ft_strchr(line, '\n') = '\0';
		map->width = ft_count_points(line, ' ');
		map->height++;
		free(line);
	}
	map->map = malloc(map->width * map->height * sizeof(t_3d_points));
	if (!map->map)
		return (FAILURE);
	close(fd);
	return (SUCCESS);
}

int	parse_file(t_map *map, char *filename)
{
	int			x;
	int			y;
	int			fd;
	char		*line;
	char		**array;
	char		**color_point;
	t_vect_3	center;

	array = NULL;
	y = 0;
	fd = open(filename, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_strchr(line, '\n'))
			*ft_strchr(line, '\n') = '\0';
		array = ft_split(line, ' ');
		x = 0;
		while (x < map->width)
		{
			color_point = ft_split(array[x], ',');
			map->map[y * map->width + x].pos.x = x * TILEZOOM;
			map->map[y * map->width + x].pos.y = y * TILEZOOM;
			map->map[y * map->width + x].pos.z = ft_atoi(color_point[0]);
			if (color_point[1] != NULL)
			{
				map->map[y * map->width + x].color = (ft_strtol(color_point[1],
							NULL, NULL, 16) << 8) | 0x000000FF;
			}
			else
				map->map[y * map->width + x].color = 0xFFFFFFFF;
			x++;
			ft_free(color_point);
		}
		y++;
		ft_free(array);
		free(line);
	}
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

// void	print_map(t_map *map)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	while (y < map->height)
// 	{
// 		x = 0;
// 		while (x < map->width)
// 		{
// 			printf("%3.0f ", map->map[y * map->width + x].pos.z);
// 			x++;
// 		}
// 		printf("\n");
// 		y++;
// 	}
// }
