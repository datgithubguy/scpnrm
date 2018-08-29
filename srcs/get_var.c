/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 02:35:31 by bal-khan          #+#    #+#             */
/*   Updated: 2018/08/29 02:35:34 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

int	get_decimal(char *s, int ret)
{
	(void)s;
	(void)ret;
	return (0);
}

int	get_integer(char *s, int ret)
{
	(void)s;
	(void)ret;
	return (0);
}

int	get_number(char *s, int ret)
{
	char	*num_str;
	int		n;
	float	f;

	if ((ret = state_float(s)))
	{
		num_str = ft_strsub(s, 0, ret);
		if (state_integer(s) == ret)
		{
			n = atoi(num_str);
			free(num_str);
			return (ret);
		}
		else
		{
			f = read_float(num_str);
			free(num_str);
			return (ret);
		}
	}
	return (0);
}
