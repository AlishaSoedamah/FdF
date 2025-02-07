#ifndef VEC_H
# define VEC_H

typedef struct s_vect_3
{
	float	x;
	float	y;
	float	z;
}			t_vect_3;

t_vect_3	vec_3(float x, float y, float z);
t_vect_3	vec_3_add(t_vect_3 a, t_vect_3 b);
t_vect_3	vec_3_scale(t_vect_3 vec, float scaler);
t_vect_3	vec_3_sub(t_vect_3 a, t_vect_3 b);

#endif