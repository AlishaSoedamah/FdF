/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:08:32 by ksoedama          #+#    #+#             */
/*   Updated: 2025/02/10 14:23:43 by ksoedama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_3d_points	rotate_x(t_3d_points pointer, double angle)
{
	double	temp_y;
	double	temp_z;

	temp_y = pointer.pos.y;
	temp_z = pointer.pos.z;
	pointer.pos.y = temp_y * cos(angle) - temp_z * sin(angle);
	pointer.pos.z = temp_y * sin(angle) + temp_z * cos(angle);
	return (pointer);
}

static t_3d_points	rotate_y(t_3d_points pointer, double angle)
{
	double	temp_x;
	double	temp_z;

	temp_x = pointer.pos.x;
	temp_z = pointer.pos.z;
	pointer.pos.x = temp_x * cos(angle) + temp_z * sin(angle);
	pointer.pos.z = -temp_x * sin(angle) + temp_z * cos(angle);
	return (pointer);
}

static t_3d_points	rotate_z(t_3d_points pointer, double angle)
{
	double	temp_x;
	double	temp_y;

	temp_x = pointer.pos.x;
	temp_y = pointer.pos.y;
	pointer.pos.x = temp_x * cos(angle) - temp_y * sin(angle);
	pointer.pos.y = temp_x * sin(angle) + temp_y * cos(angle);
	return (pointer);
}

t_3d_points	rotate_xyz(t_3d_points pointer, t_vect_3 angle)
{
	pointer = rotate_x(pointer, angle.x);
	pointer = rotate_y(pointer, angle.y);
	pointer = rotate_z(pointer, angle.z);
	return (pointer);
}
