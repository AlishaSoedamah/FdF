/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:08:32 by ksoedama          #+#    #+#             */
/*   Updated: 2025/02/07 16:24:41 by ksoedama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// |1     0           0| |x|   |        x        |   |x'|
// |0   cos θ    −sin θ| |y| = |y cos θ − z sin θ| = |y'|
// |0   sin θ     cos θ| |z|   |y sin θ + z cos θ|   |z'|
t_3d_points	rotate_x(t_3d_points pointer, double angle)
{
	double	temp_y;
	double	temp_z;

	temp_y = pointer.pos.y;
	temp_z = pointer.pos.z;
	pointer.pos.y = temp_y * cos(angle) - temp_z * sin(angle);
	pointer.pos.z = temp_y * sin(angle) + temp_z * cos(angle);
	return (pointer);
}

// // | cos θ    0   sin θ| |x|   | x cos θ + z sin θ|   |x'|
// // |   0      1       0| |y| = |         y        | = |y'|
// // |−sin θ    0   cos θ| |z|   |−x sin θ + z cos θ|   |z'|
t_3d_points	rotate_y(t_3d_points pointer, double angle)
{
	double	temp_x;
	double	temp_z;

	temp_x = pointer.pos.x;
	temp_z = pointer.pos.z;
	pointer.pos.x = temp_x * cos(angle) + temp_z * sin(angle);
	pointer.pos.z = -temp_x * sin(angle) + temp_z * cos(angle);
	return (pointer);
}

// // |cos θ   −sin θ   0| |x|   |x cos θ − y sin θ|   |x'|
// // |sin θ    cos θ   0| |y| = |x sin θ + y cos θ| = |y'|
// // |  0       0      1| |z|   |        z        |   |z'|
t_3d_points	rotate_z(t_3d_points pointer, double angle)
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