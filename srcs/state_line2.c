/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_line2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 02:37:18 by bal-khan          #+#    #+#             */
/*   Updated: 2018/08/29 02:37:21 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int	state_face_int(char *s)
{
	int	ret;

	ret = state_space(s);
	ret += state_integer(s + ret);
	while (s[ret] == '/')
		ret += state_integer(s + ret + 1) + 1;
	return (ret);
}

int	state_face(char *s)
{
	int	i;
	int	tmp;
	int	ret;

	ret = 0;
	if (s[0] == 'f')
	{
		ret = 1;
		i = 0;
		while ((tmp = state_face_int(s + ret)))
		{
			ret += tmp;
			if ((tmp = state_newline(s + ret)))
				return (ret);
			else if (i > 4)
				return (0);
			i++;
		}
	}
	return (ret);
}

int	state_mtllib(char *s)
{
	int	ret;
	int	tmp;

	ret = 0;
	if ((strncmp(s, "mtllib", 6) == 0))
	{
		tmp = 0;
		ret = 6 + state_space(s + 6);
		if ((tmp = state_name(s + ret)) &&\
			(strncmp(s + ret + tmp, ".mtl", 4) == 0))
			ret += tmp + 4;
		else
			ret = 0;
	}
	return (ret);
}
