/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 06:06:51 by bal-khan          #+#    #+#             */
/*   Updated: 2018/08/29 06:06:55 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	create_texture(t_env *e)
{
	GLuint	texture_id;
	int		width;
	int		height;

	e->texture_data = NULL;
	e->texture_data = get_bmp_img(&width, &height);
	if (!e->texture_data)
		die(e);
	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR,\
				GL_UNSIGNED_BYTE, e->texture_data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}
