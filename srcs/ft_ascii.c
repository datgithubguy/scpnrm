/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 02:34:32 by bal-khan          #+#    #+#             */
/*   Updated: 2018/08/29 02:34:35 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

int		ft_isinside(int c, int low, int high)
{
	return ((c >= low && c <= high) ? 1 : 0);
}

int		ft_isupper(int c)
{
	return (ft_isinside(c, 'A', 'Z'));
}

int		ft_islower(int c)
{
	return (ft_isinside(c, 'a', 'z'));
}

int		ft_isalpha(int c)
{
	return ((ft_islower(c) || ft_isupper(c)) ? 1 : 0);
}

int		ft_isdigit(int c)
{
	return (ft_isinside(c, '0', '9'));
}
