/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:17:15 by ksoedama          #+#    #+#             */
/*   Updated: 2025/02/14 14:43:25 by ksoedama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_3d_points	isometric(t_3d_points coordinates)
{
	float	tmp;

	tmp = coordinates.pos.x;
	coordinates.pos.x = (tmp - coordinates.pos.y) * cos(0.523599);
	coordinates.pos.y = (tmp + coordinates.pos.y) * sin(0.523599)
		- coordinates.pos.z;
	return (coordinates);
}
