/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 02:36:31 by bal-khan          #+#    #+#             */
/*   Updated: 2018/08/29 02:36:34 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_quat	q_add(t_quat q0, t_quat q1)
{
	t_quat	ret;

	ret.x = q0.x + q1.x;
	ret.y = q0.y + q1.y;
	ret.z = q0.z + q1.z;
	ret.w = q0.w + q1.w;
	return (ret);
}

t_quat	q_subb(t_quat q0, t_quat q1)
{
	t_quat	ret;

	ret.x = q0.x - q1.x;
	ret.y = q0.y - q1.y;
	ret.z = q0.z - q1.z;
	ret.w = q0.w - q1.w;
	return (ret);
}

t_quat	q_smul(float scalar, t_quat q0)
{
	t_quat	ret;

	ret.x = q0.x * scalar;
	ret.y = q0.y * scalar;
	ret.z = q0.z * scalar;
	ret.w = q0.w * scalar;
	return (ret);
}

double	calc(double dot, float t, int is_s0)
{
	double	theta_0;
	double	theta;
	double	sin_theta;
	double	sin_theta_0;

	theta_0 = acos(dot);
	theta = theta_0 * t;
	sin_theta = sin(theta);
	sin_theta_0 = sin(theta_0);
	if (is_s0)
		return (cos(theta) - dot * sin_theta / sin_theta_0);
	else
		return (sin_theta / sin_theta_0);
}

t_quat	slerp(t_quat q0, t_quat q1, float t)
{
	t_quat	ret;
	double	dot;

	dot = dot_product(q0, q1);
	if (dot <= .0)
	{
		q1 = q_smul(-1., q1);
		dot = -dot;
	}
	if (dot > .90)
	{
		ret = normalize(q_add(q0, q_smul(t, q_subb(q1, q0))));
		return (ret);
	}
	return (q_add(q_smul(calc(dot, t, 0), q0), q_smul(calc(dot, t, 1), q1)));
}
