/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 02:37:33 by bal-khan          #+#    #+#             */
/*   Updated: 2018/08/29 02:37:36 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int	state_start(char *s, t_obj *obj)
{
	t_list	*verts_lst;
	t_list	*faces_lst;
	int		ret;
	int		tmp;
	int		j;

	j = 0;
	ret = 0;
	verts_lst = NULL;
	faces_lst = NULL;
	while ((tmp = state_line(s + ret, &verts_lst, &faces_lst)))
	{
		ret += tmp;
		if ((tmp = state_newline(s + ret)))
			ret += tmp;
		j++;
	}
	assign_vertices(verts_lst, obj);
	assign_faces(faces_lst, obj);
	return (ret);
}

int	state_line(char *s, t_list **verts, t_list **faces)
{
	static int	(*states[])(char *) = {state_vertex, state_face,
		state_mtllib, state_object, state_use_material, state_group,
		state_comment};
	static int	(*get[])(char *, int, t_list **) = {get_vertex, get_face,
		get_mtllib, get_object, get_use_material, get_group, get_comment};
	int			i;
	int			ret;
	int			tmp;

	ret = 0;
	tmp = 0;
	i = 0;
	while (i < 7)
	{
		if ((tmp = states[i](s + ret)))
		{
			if (!(get[i](s + ret, tmp, (i == 0) ? verts : faces)))
				return (0);
			ret += tmp;
			break ;
		}
		i++;
	}
	return (ret);
}
