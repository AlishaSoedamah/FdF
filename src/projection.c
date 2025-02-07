/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:42:45 by ksoedama          #+#    #+#             */
/*   Updated: 2025/02/07 17:44:55 by ksoedama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// x' = (x-z)/ sqrt(2)
// y' = (x + 2y + z) / sqrt(6)

t_3d_points	isometric(t_3d_points coordinates, unsigned int width,
		unsigned int height)
{
	float	tmp;

	tmp = coordinates.pos.x;
	coordinates.pos.x = (tmp - coordinates.pos.y) / SQRT2;
	coordinates.pos.y = (tmp + coordinates.pos.z - 2 * coordinates.pos.z)
		/ SQRT6;
	coordinates.pos.z = (tmp - coordinates.pos.x);
	return (coordinates);
}

