/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 02:34:59 by bal-khan          #+#    #+#             */
/*   Updated: 2018/08/29 02:35:03 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

int	get_face_ind(char *s, int len, int i, t_faces *face)
{
	char	*num_str;
	int		tmp;

	if ((tmp = state_integer(s + len)))
	{
		num_str = ft_strsub(s, len, tmp);
		len += state_face_int(s + len);
		face->indexes[i] = (int)atoi(num_str);
		free(num_str);
		face->count++;
	}
	else if (i < 3)
		return (0);
	return (len);
}

int	get_face(char *s, int ret, t_list **lst)
{
	t_faces	*face;
	int		len;
	int		i;

	i = 0;
	len = 1 + state_space(s + 1);
	if ((face = (t_faces*)malloc(sizeof(t_faces))) == NULL)
		die(NULL);
	if ((face->indexes = (int*)malloc(sizeof(int) * 4)) == NULL)
		die(NULL);
	face->count = 0;
	while (i < 4)
	{
		len = get_face_ind(s, len, i, face);
		len += state_space(s + len);
		i++;
	}
	ft_lstadd_end(lst, ft_lstnew((void const*)face, sizeof(t_faces)));
	free(face);
	return (ret);
}
