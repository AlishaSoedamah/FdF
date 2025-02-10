/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:24:18 by ksoedama          #+#    #+#             */
/*   Updated: 2025/02/10 12:22:27 by ksoedama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vect_3	vec_3(float x, float y, float z)
{
	t_vect_3	vec3;

	vec3.x = x;
	vec3.y = y;
	vec3.z = z;
	return (vec3);
}

t_vect_3	vec_3_add(t_vect_3 a, t_vect_3 b)
{
	t_vect_3	out;

	out.x = a.x + b.x;
	out.y = a.y + b.y;
	out.z = a.z + b.z;
	return (out);
}

t_vect_3	vec_3_sub(t_vect_3 a, t_vect_3 b)
{
	t_vect_3	out;

	out.x = a.x - b.x;
	out.y = a.y - b.y;
	out.z = a.z - b.z;
	return (out);
}

t_vect_3	vec_3_scale(t_vect_3 vec, float scaler)
{
	t_vect_3	zoomed_vec;

	zoomed_vec.x = vec.x * scaler;
	zoomed_vec.y = vec.y * scaler;
	zoomed_vec.z = vec.z * scaler;
	return (zoomed_vec);
}
