/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 02:34:47 by bal-khan          #+#    #+#             */
/*   Updated: 2018/08/29 02:38:32 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

int		ft_isalnum(int c)
{
	return ((ft_isalpha(c) || ft_isdigit(c)) ? 1 : 0);
}

int		ft_iswhite(char c)
{
	return ((c == '\v' || c == '\r' || c == ' ' || c == '\f'
				|| c == '\t' || c == '\n') ? 1 : 0);
}

int		ft_isblank(char c)
{
	return ((c == '\t' || c == '\n' || c == ' '));
}

int		ft_isspace(char c)
{
	return ((c == '\t' || c == ' '));
}

int		ft_isnamechar(char c)
{
	return ((c == '-' || c == '_' || c == '(' || c == ')' || c == '~'));
}
