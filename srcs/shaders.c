/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 02:37:04 by bal-khan          #+#    #+#             */
/*   Updated: 2018/08/29 02:37:07 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

int		log_error(GLuint *shader, char *type)
{
	GLint	log_size;
	GLint	max_length;
	char	*error_log;

	log_size = 1000;
	max_length = 1000;
	glGetShaderiv(*shader, GL_INFO_LOG_LENGTH, &log_size);
	if ((error_log = (char *)malloc(sizeof(char) * log_size)) == NULL)
		return (-1);
	glGetShaderInfoLog(*shader, max_length, &max_length, &error_log[0]);
	printf("could not compile %s shader\n", type);
	printf("%s\n", error_log);
	return (-1);
}

int		compile_shader(t_env *e, GLenum shader_type, GLuint *shader, \
					char *shader_str)
{
	char	*type;
	GLint	is_compiled;

	is_compiled = 0;
	(void)e;
	create_texture();
	if (shader_type == GL_VERTEX_SHADER)
		type = "vertex";
	if (shader_type == GL_FRAGMENT_SHADER)
		type = "fragment";
	*shader = glCreateShader(shader_type);
	if (!shader || !shader_str)
	{
		printf("|%s|\n", shader_str);
		die(e);
	}
	glShaderSource(*shader, 1, (const GLchar *const *)(&shader_str), NULL);
	glCompileShader(*shader);
	glGetShaderiv(*shader, GL_COMPILE_STATUS, &is_compiled);
	if (is_compiled == GL_FALSE)
	{
		log_error(shader, type);
		return (-1);
	}
	return (0);
}

void	compile_shaders(t_env *e)
{
	char *file_str;

	file_str = read_file("./shaders/vert.vs");
	compile_shader(e, GL_VERTEX_SHADER, &e->vs, file_str);
	free(file_str);
	file_str = read_file("./shaders/frag.fs");
	compile_shader(e, GL_FRAGMENT_SHADER, &e->fs, file_str);
	free(file_str);
	e->shader_programme = glCreateProgram();
	glAttachShader(e->shader_programme, e->vs);
	glAttachShader(e->shader_programme, e->fs);
	glLinkProgram(e->shader_programme);
	glUseProgram(e->shader_programme);
}
