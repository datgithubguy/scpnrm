/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_quats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 02:35:46 by bal-khan          #+#    #+#             */
/*   Updated: 2018/08/29 02:35:48 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_quat	init_quat_test(void)
{
	t_quat	quat_test;

	quat_test.x = .0;
	quat_test.y = 1.0;
	quat_test.z = .0;
	quat_test.w = 1.0;
	quat_test = normalize(quat_test);
	return (quat_test);
}

t_quat	get_result_quat(float t)
{
	t_quat	q1;

	q1.x = .0;
	q1.y = .0;
	q1.z = .0;
	q1.w = 1.0;
	q1 = normalize(q1);
	return (normalize(slerp(q1, init_quat_test(), fmod(t, 4.) - 0.)));
}
