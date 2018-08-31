/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_faces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 02:36:15 by bal-khan          #+#    #+#             */
/*   Updated: 2018/08/31 05:06:18 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	make_faces(float **faces, t_faces *f, t_vec3 *v, t_env *e)
{
	e->i[0] = -1;
	e->i[2] = 0;
	while (++(e->i[0]) < e->obj.raw_face_count)
	{
		e->i[1] = -1;
		while (++(e->i[1]) < 3)
		{
			if (f[e->i[0]].indexes[e->i[1]] > e->obj.num_v)
				die(e);
			*(t_vec3*)((*faces) + ((e->i[0] +\
				e->i[2]) * 3 * 3 + e->i[1] * 3)) =
				v[f[e->i[0]].indexes[e->i[1]] - 1];
		}
		make_quad_faces(faces, f, v, e);
	}
}

void	make_quad_faces(float **faces, t_faces *f, t_vec3 *v, t_env *e)
{
	if (f[e->i[0]].count == 4)
	{
		e->i[1] = 0;
		if (f[e->i[0]].indexes[e->i[1] + 1] > e->obj.num_v)
			die(e);
		*(t_vec3*)((*faces) + ((e->i[0] + 1 + e->i[2]) * 3 * 3)) =
			v[f[e->i[0]].indexes[e->i[1]] - 1];
		while (++(e->i[1]) < 3)
		{
			if (f[e->i[0]].indexes[e->i[1] + 1] > e->obj.num_v)
				die(e);
			*(t_vec3*)((*faces) + ((e->i[0] + 1 + e->i[2]) * 3 * 3\
				+ e->i[1] * 3)) =
				v[f[e->i[0]].indexes[e->i[1] + 1] - 1];
		}
		(e->i[2])++;
	}
}
