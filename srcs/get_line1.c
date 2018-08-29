/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 02:34:53 by bal-khan          #+#    #+#             */
/*   Updated: 2018/08/29 02:34:56 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

int	get_v(char *s, int ret, t_vec3 *v)
{
	char	*num_str;
	float	f;
	int		len;
	int		tmp;
	int		i;

	i = 0;
	f = 0.0;
	len = 1 + state_space(s + 1);
	while (i < 3)
	{
		if ((tmp = state_float(s + len)))
		{
			num_str = ft_strsub(s, len, tmp);
			len += tmp;
			f = read_float(num_str);
			((float*)v)[i] = f;
			free(num_str);
		}
		else
			return (0);
		len += state_space(s + len);
		i++;
	}
	return (len == ret);
}

int	get_vt(char *s, int ret, t_vec3 *v)
{
	char	*num_str;
	float	f;
	int		len;
	int		tmp;
	int		i;

	i = 0;
	len = 2 + state_space(s + 2);
	while (i < 2)
	{
		if ((tmp = state_float(s + len)))
		{
			num_str = ft_strsub(s, len, tmp);
			len += tmp;
			f = read_float(num_str);
			((float*)v)[i] = f;
			free(num_str);
		}
		else
			return (0);
		len += state_space(s + len);
		i++;
	}
	return (len == ret);
}

int	get_vn(char *s, int ret, t_vec3 *v)
{
	char	*num_str;
	float	f;
	int		len;
	int		tmp;
	int		i;

	i = 0;
	len = 2 + state_space(s + 2);
	while (i < 3)
	{
		if ((tmp = state_float(s + len)))
		{
			num_str = ft_strsub(s, len, tmp);
			len += tmp;
			f = read_float(num_str);
			((float*)v)[i] = f;
			free(num_str);
		}
		else
			return (0);
		len += state_space(s + len);
		i++;
	}
	return (len == ret);
}

int	get_vp(char *s, int ret, t_vec3 *v)
{
	char	*num_str;
	float	f;
	int		len;
	int		tmp;
	int		i;

	i = 0;
	len = 2 + state_space(s + 2);
	while (i < 2)
	{
		if ((tmp = state_float(s + len)))
		{
			num_str = ft_strsub(s, len, tmp);
			len += tmp;
			f = read_float(num_str);
			((float*)v)[i] = f;
			free(num_str);
		}
		else
			return (0);
		len += state_space(s + len);
		i++;
	}
	return (len == ret);
}

int	get_vertex(char *s, int ret, t_list **lst)
{
	t_vec3		v;
	static int	(*get_vert_type[])(char *, int, t_vec3 *) = {get_v, get_vt,\
															get_vn, get_vp};
	int			vt;
	int			i;
	static int	k = 0;

	k++;
	vt = check_vertex_type(s);
	i = 0;
	while (i < 4)
	{
		if (i == vt - 1)
		{
			get_vert_type[i](s, ret, &v);
			ft_lstadd_end(lst, ft_lstnew((void const*)&v, sizeof(t_vec3)));
		}
		i++;
	}
	return (ret);
}
