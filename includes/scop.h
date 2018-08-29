/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 02:38:17 by bal-khan          #+#    #+#             */
/*   Updated: 2018/08/29 02:38:20 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# define GLFW_INCLUDE_GLCOREARB
# include "/Users/bal-khan/glfw/include/GLFW/glfw3.h"
# include "quaternions.h"
# include "bmp_reader.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <time.h>
# include <sys/stat.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_vec3
{
	float	x;
	float	y;
	float	z;
}				t_vec3;

typedef struct	s_faces
{
	int		*indexes;
	int		count;
}				t_faces;

typedef struct	s_obj
{
	t_vec3		*vertices;
	t_faces		*faces;
	float		*faces_arr;
	GLuint		vbo;
	GLuint		vao;
	int			raw_face_count;
	int			tri_face_count;
	int			num_v;
	float		scale;
	t_vec3		median;
}				t_obj;

typedef struct	s_env
{
	GLFWwindow	*window;
	GLuint		vs;
	GLuint		fs;
	GLuint		shader_programme;
	t_vec3		displ;
	t_obj		obj;
	char		*texture_data;
}				t_env;

void			create_texture(t_env *e);
void			find_median_point(t_vec3 *v, t_obj *obj);
float			get_current_time();
void			die(t_env *e);
void			parse_file(char *obj_path, t_obj *obj);
void			make_faces(float **f, t_faces *fi, t_vec3 *vertices, t_env *e);
float			get_current_time();

void			render(t_env *e);
char			*read_file(char *filepath);
void			compile_shaders(t_env *e);
void			init_scop(t_env *e, char *path);

int				state_start(char *s, t_obj *obj);
int				state_line(char *s, t_list **verts, t_list **faces);
int				state_vertex(char *s);
int				state_face(char *s);
int				state_face_int(char *s);
int				state_mtllib(char *s);
int				state_object(char *s);
int				state_use_material(char *s);
int				state_group(char *s);
int				state_comment(char *s);
int				check_vertex_type(char *s);
int				get_vertex(char *s, int ret, t_list **lst);
int				get_face(char *s, int ret, t_list **lst);
int				get_mtllib(char *s, int ret, t_list **lst);
int				get_object(char *s, int ret, t_list **lst);
int				get_use_material(char *s, int ret, t_list **lst);
int				get_group(char *s, int ret, t_list **lst);
int				get_comment(char *s, int ret, t_list **lst);
int				assign_vertices(t_list	*verts_lst, t_obj *obj);
int				assign_faces(t_list	*faces_lst, t_obj *obj);

int				state_decimal(char *s);
int				get_decimal(char *s, int ret);
int				get_integer(char *s, int ret);
int				state_name(char *s);
int				state_float(char *s);
int				state_integer(char *s);

char			*ft_strsub(char const *s, unsigned int start, size_t len);
float			read_float2(char *p, float integer, float floating, int sign);
float			read_float(char *s);
int				get_number(char *s, int ret);

int				state_white_space(char *s);
int				state_space(char *s);
int				state_newline(char *s);

int				ft_isinside(int c, int low, int high);
int				ft_isupper(int c);
int				ft_islower(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_iswhite(char c);
int				ft_isblank(char c);
int				ft_isspace(char c);
int				ft_isnamechar(char c);

void			ft_memdel(void **ap);
void			*ft_memalloc(size_t size);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstadd(t_list **alst, t_list *node);
void			ft_lstadd_end(t_list **alst, t_list *node);
size_t			ft_lstsize(t_list *root);

void			sum_indexes(t_list *faces, t_obj *obj);

#endif
