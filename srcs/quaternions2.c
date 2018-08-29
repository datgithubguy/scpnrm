/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternions2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 02:36:38 by bal-khan          #+#    #+#             */
/*   Updated: 2018/08/29 02:36:41 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_quat	quat_mult(t_quat q1, t_quat q2)
{
	t_quat ret;

	ret.x = +q1.w * q2.x - q1.z * q2.y + q1.y * q2.z + q1.x * q2.w;
	ret.y = +q1.z * q2.x + q1.w * q2.y - q1.x * q2.z + q1.y * q2.w;
	ret.z = -q1.y * q2.x + q1.x * q2.y + q1.w * q2.z + q1.z * q2.w;
	ret.w = -q1.x * q2.x - q1.y * q2.y - q1.z * q2.z + q1.w * q2.w;
	return (ret);
}

t_mat	quat_to_rot_mat(t_quat q)
{
	t_mat	ret;

	bzero(&ret.mat, 16 * sizeof(float));
	ret.mat[0][0] = q.w * q.w + q.x * q.x - q.y * q.y - q.z * q.z;
	ret.mat[0][1] = 2 * (-q.w * q.z + q.x * q.y);
	ret.mat[0][2] = 2 * (q.w * q.y + q.x * q.z);
	ret.mat[1][0] = 2 * (q.w * q.z + q.x * q.y);
	ret.mat[1][1] = q.w * q.w - q.x * q.x + q.y * q.y - q.z * q.z;
	ret.mat[1][2] = 2 * (-q.w * q.x + q.y * q.z);
	ret.mat[2][0] = 2 * (-q.w * q.y + q.x * q.z);
	ret.mat[2][1] = 2 * (q.w * q.x + q.y * q.z);
	ret.mat[2][2] = q.w * q.w - q.x * q.x - q.y * q.y + q.z * q.z;
	ret.mat[3][3] = (q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z);
	return (ret);
}

t_quat	normalize(t_quat q)
{
	t_quat	ret;
	float	norm;

	norm = sqrt(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w);
	ret.x = q.x / norm;
	ret.y = q.y / norm;
	ret.z = q.z / norm;
	ret.w = q.w / norm;
	return (ret);
}

t_quat	euler_to_quat(t_euler euler)
{
	t_quat	ret;
	float	a[5];

	a[0] = 0.5 * euler.y;
	a[1] = 0.5 * (euler.x - euler.z);
	a[2] = 0.5 * (euler.x + euler.z);
	a[3] = sin(a[0]);
	a[4] = cos(a[0]);
	ret.x = a[3] * cos(a[1]);
	ret.y = a[3] * sin(a[1]);
	ret.z = a[4] * sin(a[2]);
	ret.w = a[4] * cos(a[2]);
	ret = normalize(ret);
	return (ret);
}

float	dot_product(t_quat q0, t_quat q1)
{
	float	ret;

	ret = q0.x * q1.x + q0.y * q1.y + q0.z * q1.z + q0.w * q1.w;
	return (ret);
}
