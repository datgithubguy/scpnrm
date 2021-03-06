/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_var2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 02:37:47 by bal-khan          #+#    #+#             */
/*   Updated: 2018/08/29 02:37:50 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int	state_integer(char *s)
{
	char	*p;

	p = s;
	if (*s == '-')
		s++;
	while (ft_isdigit(*s))
		s++;
	return (s - p);
}
