/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 22:30:30 by bal-khan          #+#    #+#             */
/*   Updated: 2018/05/24 22:32:49 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUATERNIONS_H
# define QUATERNIONS_H
# include <math.h>

typedef struct	s_quat
{
	float	w;
	float	x;
	float	y;
	float	z;
}				t_quat;

typedef struct	s_mat
{
	float	mat[4][4];
}				t_mat;

typedef struct	s_euler
{
	float	x;
	float	y;
	float	z;
}				t_euler;

t_mat			quat_to_rot_mat(t_quat q);
t_quat			quat_mult(t_quat q1, t_quat q2);
t_quat			euler_to_quat(t_euler euler);
t_quat			slerp(t_quat q0, t_quat q1, float t);
t_quat			q_add(t_quat q0, t_quat q1);
t_quat			q_subb(t_quat q0, t_quat q1);
t_quat			get_result_quat(float t);
t_quat			normalize(t_quat q);
float			dot_product(t_quat q0, t_quat q1);

#endif
