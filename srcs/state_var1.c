/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_var1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 02:37:39 by bal-khan          #+#    #+#             */
/*   Updated: 2018/08/29 02:37:43 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int	state_decimal(char *s)
{
	(void)s;
	return (0);
}

int	state_name(char *s)
{
	char	*p;

	p = s;
	while (ft_isalnum(*s) || ft_isnamechar(*s))
		s++;
	return (s - p);
}

int	state_space(char *s)
{
	char	*p;

	p = s;
	while (ft_isspace(*s))
		s++;
	return (s - p);
}

int	state_white_space(char *s)
{
	char	*p;

	p = s;
	while (ft_iswhite(*s))
		s++;
	return (p - s);
}

int	state_float(char *s)
{
	int	ret;

	ret = 0;
	if ((ret = state_integer(s)) > 0)
	{
		if (*(s + ret) == '.')
		{
			ret++;
			while (ft_isdigit(s[ret]))
				ret++;
		}
	}
	return (ret);
}
