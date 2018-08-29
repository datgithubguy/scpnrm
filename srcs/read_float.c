/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 02:36:53 by bal-khan          #+#    #+#             */
/*   Updated: 2018/08/29 02:36:56 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s2;
	size_t	i;
	size_t	len;

	len = strlen(s1);
	len = (len > n) ? n : len;
	s2 = (char *)malloc(len + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	return (ft_strndup(s + start, len));
}

float	read_float2(char *p, float integer, float floating, int sign)
{
	int		exponent;

	exponent = !p ? 0 : atoi(p + 1);
	integer += floating;
	while (exponent++ < 0)
		integer /= 10;
	while (--exponent > 0)
		integer *= 10;
	return (sign * integer);
}

float	read_float(char *s)
{
	char	*p;
	float	integer;
	float	floating;
	char	*c;
	int		sign;

	if (!s)
		return (0);
	sign = *s == '-' ? -1 : 1;
	s += *s == '-';
	integer = (float)atoi(s);
	if ((p = strchr(s, '.')) == NULL)
		return (sign * integer);
	c = p + 1;
	while (c && ft_isdigit(*c))
		c++;
	floating = (float)(!p ? 0 : atoi(p + 1));
	floating /= pow(10, c - p - 1);
	p = strchr(s, 'e');
	p = p ? p : strchr(s, 'E');
	return (read_float2(p, integer, floating, sign));
}
