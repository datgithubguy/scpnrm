/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 02:33:54 by bal-khan          #+#    #+#             */
/*   Updated: 2018/08/29 02:34:02 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		assign_vertex(t_vec3 *v, t_vec3 *verts, t_obj *obj)
{
	*((t_vec3*)(verts)) = *v;
	obj->num_v++;
	return (0);
}

int		assign_vertices(t_list *v_lst, t_obj *obj)
{
	t_list	*elem;
	t_list	*tmp;
	t_vec3	**verts;
	t_vec3	*v;
	int		j;

	obj->median = (t_vec3){.0, .0, .0};
	verts = &(obj)[0].vertices;
	if (!(*verts = (t_vec3*)malloc(sizeof(t_vec3) * ft_lstsize(v_lst))))
		die(NULL);
	elem = v_lst;
	j = 0;
	obj->num_v = 0;
	while (elem)
	{
		v = elem->content;
		assign_vertex(v, &(*verts)[j], obj);
		find_median_point(v, obj);
		tmp = elem;
		elem = elem->next;
		free(tmp->content);
		free(tmp);
		j++;
	}
	return (0);
}

void	find_median_point(t_vec3 *v, t_obj *obj)
{
	obj->median.x += v->x;
	obj->median.y += v->y;
	obj->median.z += v->z;
}

int		assign_faces(t_list *faces_lst, t_obj *obj)
{
	t_list	*elem;
	t_list	*tmp;
	t_faces	**faces;
	t_faces	*face;
	int		j;

	faces = &obj->faces;
	sum_indexes(faces_lst, obj);
	if (!(*faces = (t_faces*)malloc(sizeof(t_faces) * obj->raw_face_count)))
		die(NULL);
	elem = faces_lst;
	j = 0;
	while (j < obj->raw_face_count && elem)
	{
		face = elem->content;
		(*faces)[j].indexes = face->indexes;
		(*faces)[j].count = face->count;
		tmp = elem;
		elem = elem->next;
		free(tmp->content);
		free(tmp);
		j++;
	}
	return (0);
}
