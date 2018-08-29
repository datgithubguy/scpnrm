/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 02:34:11 by bal-khan          #+#    #+#             */
/*   Updated: 2018/08/29 02:34:18 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	die(t_env *e)
{
	int	i;

	write(1, "die !\n", 6);
	if (e)
	{
		if (e->texture_data)
			free(e->texture_data);
		if (e->obj.vertices)
			free(e->obj.vertices);
		if (e->obj.faces)
		{
			i = -1;
			while (++i < e->obj.raw_face_count)
				free(e->obj.faces[i].indexes);
			free(e->obj.faces);
		}
		if (e->obj.faces_arr)
			free(e->obj.faces_arr);
	}
	glfwTerminate();
	exit(-1);
}
