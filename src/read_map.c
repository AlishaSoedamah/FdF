/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:27:18 by ksoedama          #+#    #+#             */
/*   Updated: 2025/02/14 16:54:49 by ksoedama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		if (map->width == 0)
			map->width = ft_count_points(line, ' ');
		else if (map->width != ft_count_points(line, ' '))
			return (free(line), close(fd), FAILURE);
		map->height++;
		free(line);
	}
	map->map = malloc(map->width * map->height * sizeof(t_3d_points));
	if (!map->map)
		return (FAILURE);
	close(fd);
	return (SUCCESS);
}
