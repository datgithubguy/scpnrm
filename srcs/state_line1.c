/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_line1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 02:37:11 by bal-khan          #+#    #+#             */
/*   Updated: 2018/08/29 02:37:14 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int	state_newline(char *s)
{
	int	i;

	i = 0;
	while (s[i] == '\n')
	{
		i++;
	}
	return (i);
}

int	check_vertex_type(char *s)
{
	if (strncmp(s, "v", 1) == 0 && state_space(s + 1))
		return (1);
	return (0);
}

int	state_vertex(char *s)
{
	int		i;
	int		ret;
	int		is_vec2;

	i = check_vertex_type(s);
	if (i == 0)
		return (0);
	ret = (i == 1) ? 1 : 2;
	ret += state_space(s + ret);
	is_vec2 = (i == 2 || i == 4) ? 1 : 0;
	i = (is_vec2) ? 1 : 0;
	while (i < 3)
	{
		ret += state_float(s + ret);
		ret += state_space(s + ret);
		i++;
	}
	return (ret);
}
