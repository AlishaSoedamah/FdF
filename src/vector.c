/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:24:18 by ksoedama          #+#    #+#             */
/*   Updated: 2025/02/16 11:43:26 by ksoedama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vect_3	vec_3(double x, double y, double z)
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
