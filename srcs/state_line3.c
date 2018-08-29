/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_line3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 02:37:25 by bal-khan          #+#    #+#             */
/*   Updated: 2018/08/29 02:37:28 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int	state_object(char *s)
{
	int	tmp;
	int	ret;

	ret = 0;
	if (s[0] == 'o')
	{
		ret = 1 + state_space(s + 1);
		if ((tmp = state_name(s + ret)))
			ret += tmp;
		else
			ret = 0;
	}
	return (ret);
}

int	state_use_material(char *s)
{
	int	ret;
	int	tmp;

	ret = 0;
	if ((strncmp(s, "usemtl", 6) == 0))
	{
		tmp = 0;
		ret = 6 + state_space(s + 6);
		if ((tmp = state_name(s + ret)))
			ret += tmp;
		else
			ret = 0;
	}
	return (ret);
}

int	state_group(char *s)
{
	int	ret;

	ret = 0;
	if (s[0] == 's')
	{
		ret = 1 + state_space(s + 1);
		if ((strncmp(s + ret, "on", 2)) == 0)
			ret += 2;
		else if ((strncmp(s + ret, "off", 3)) == 0)
			ret += 3;
		else
			ret = 0;
	}
	return (ret);
}

int	state_comment(char *s)
{
	int ret;
	int i;

	ret = 0;
	if (s[0] == '#')
	{
		i = 1;
		while (!(state_newline(s + i)))
			i++;
		ret += i;
	}
	return (ret);
}
