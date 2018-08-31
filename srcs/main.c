/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 02:36:08 by bal-khan          #+#    #+#             */
/*   Updated: 2018/08/29 02:36:11 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void	key_callback(GLFWwindow *window, int key, int scancode, int action,\
						int mods)
{
	static GLFWwindow *w = NULL;

	(void)scancode;
	(void)mods;
	if (!w)
		w = glfwGetWindowUserPointer(window);
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, 1);
	if (key == GLFW_KEY_RIGHT && action & (GLFW_REPEAT | GLFW_PRESS))
		((t_env *)w)->displ.x += .051;
	if (key == GLFW_KEY_LEFT && action & (GLFW_REPEAT | GLFW_PRESS))
		((t_env *)w)->displ.x -= .051;
	if (key == GLFW_KEY_UP && action & (GLFW_REPEAT | GLFW_PRESS))
		((t_env *)w)->displ.y += .051;
	if (key == GLFW_KEY_DOWN && action & (GLFW_REPEAT | GLFW_PRESS))
		((t_env *)w)->displ.y -= .051;
	if (key == GLFW_KEY_P && action & (GLFW_REPEAT | GLFW_PRESS))
		((t_env *)w)->displ.z += .051;
	if (key == GLFW_KEY_O && action & (GLFW_REPEAT | GLFW_PRESS))
		((t_env *)w)->displ.z -= .051;
	if (key == GLFW_KEY_A && action & (GLFW_REPEAT | GLFW_PRESS))
		((t_env *)w)->obj.toogle = 0.0;
	if (key == GLFW_KEY_Z && action & (GLFW_REPEAT | GLFW_PRESS))
		((t_env *)w)->obj.toogle = 1.0;
}

int			gen_vbo_vao(t_env *e, float *faces)
{
	t_obj	obj;

	obj = e->obj;
	glGenBuffers(1, &(obj.vbo));
	glBindBuffer(GL_ARRAY_BUFFER, obj.vbo);
	glBufferData(GL_ARRAY_BUFFER, obj.tri_face_count * 9 * sizeof(float),\
				&faces[0], GL_STATIC_DRAW);
	glGenVertexArrays(1, &(obj.vao));
	glBindVertexArray(obj.vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, obj.vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	e->obj = obj;
	return (0);
}

int			load_obj(t_env *e, char *path)
{
	float	*faces;

	parse_file(path, &(e->obj));
	if ((e->obj.faces_arr = (float *)malloc(e->obj.tri_face_count * 3\
					* 3 * sizeof(float))) == NULL)
		die(NULL);
	faces = e->obj.faces_arr;
	bzero(faces, (e->obj).num_v * 3 * sizeof(float));
	make_faces(&faces, e->obj.faces, e->obj.vertices, e);
	gen_vbo_vao(e, faces);
	return (0);
}

void		init_scop(t_env *e, char *path)
{
	load_obj(e, path);
	compile_shaders(e);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
}

int			main(int ac, char **av)
{
	t_env	e;

	bzero(&e, sizeof(t_env));
	if (ac != 2)
		die(NULL);
	if (!glfwInit())
		write(1, "failed init !\n", 14);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	e.window = glfwCreateWindow(1920, 1440, "Scop", NULL, NULL);
	if (!e.window)
		die(NULL);
	glfwMakeContextCurrent(e.window);
	glfwSetWindowUserPointer(e.window, &e);
	glfwSetKeyCallback(e.window, key_callback);
	e.obj.toogle = 1.;
	init_scop(&e, av[ac - 1]);
	while (!glfwWindowShouldClose(e.window))
		render(&e);
	glfwDestroyWindow(e.window);
	die(&e);
	return (0);
}
