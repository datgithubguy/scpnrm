/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 02:34:24 by bal-khan          #+#    #+#             */
/*   Updated: 2018/08/29 02:34:26 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	draw_obj(t_env *e)
{
	t_obj	obj;

	obj = e->obj;
	glDrawArraysInstanced(GL_TRIANGLES, 0, obj.num_v * sizeof(float), 1);
}

void	render(t_env *e)
{
	t_mat			rot;
	static GLint	loc[4];
	float			t;

	if (!loc[0])
		loc[0] = glGetUniformLocation(e->shader_programme, "time");
	if (!loc[1])
		loc[1] = glGetUniformLocation(e->shader_programme, "matrix");
	if (!loc[2])
		loc[2] = glGetUniformLocation(e->shader_programme, "displ");
	if (!loc[3])
		loc[3] = glGetUniformLocation(e->shader_programme, "scale");
	t = get_current_time();
	rot = quat_to_rot_mat(get_result_quat(t));
	glProgramUniformMatrix4fv(e->shader_programme, loc[1], 1, GL_FALSE,\
							(float *)rot.mat);
	glProgramUniform1f(e->shader_programme, loc[0], t);
	glProgramUniform1f(e->shader_programme, loc[3], e->obj.scale);
	glProgramUniform3f(e->shader_programme, loc[2], e->displ.x, e->displ.y,\
	e->displ.z);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	draw_obj(e);
	glfwPollEvents();
	glfwSwapBuffers(e->window);
}
