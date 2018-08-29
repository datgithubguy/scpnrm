/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 02:36:22 by bal-khan          #+#    #+#             */
/*   Updated: 2018/08/29 02:36:25 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	parse_file(char *obj_path, t_obj *obj)
{
	char	*s;

	s = read_file(obj_path);
	state_start(s, obj);
	free(s);
}
