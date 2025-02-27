/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:55:01 by ksoedama          #+#    #+#             */
/*   Updated: 2025/02/16 11:43:18 by ksoedama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vect_3
{
	double	x;
	double	y;
	double	z;
}			t_vect_3;

t_vect_3	vec_3(double x, double y, double z);
t_vect_3	vec_3_add(t_vect_3 a, t_vect_3 b);
t_vect_3	vec_3_sub(t_vect_3 a, t_vect_3 b);

#endif