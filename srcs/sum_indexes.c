/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_indexes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 02:37:55 by bal-khan          #+#    #+#             */
/*   Updated: 2018/08/29 02:37:58 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	sum_indexes(t_list *faces, t_obj *obj)
{
	int r_count;
	int t_count;

	r_count = 0;
	t_count = 0;
	while (faces)
	{
		r_count++;
		if (((t_faces*)(faces->content))->count == 4)
			t_count += 2;
		else if (((t_faces*)(faces->content))->count == 3)
			t_count++;
		else
			die(NULL);
		faces = faces->next;
	}
	obj->raw_face_count = r_count;
	obj->tri_face_count = t_count;
}
