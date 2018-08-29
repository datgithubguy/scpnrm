/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 02:35:54 by bal-khan          #+#    #+#             */
/*   Updated: 2018/08/29 02:35:56 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	ft_memdel(void **ap)
{
	if (*ap)
		free(*ap);
	*ap = NULL;
}

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	if ((ptr = malloc(size)) == NULL)
		return (NULL);
	bzero(ptr, size);
	return (ptr);
}

size_t	ft_lstsize(t_list *root)
{
	size_t	size;

	size = 0;
	while (root)
	{
		++size;
		root = root->next;
	}
	return (size);
}

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (alst != NULL)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			if (new)
			{
				new->next = *alst;
				*alst = new;
			}
		}
	}
}

void	ft_lstadd_end(t_list **alst, t_list *new)
{
	if (alst)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			if ((*alst)->next)
				ft_lstadd_end(&((*alst)->next), new);
			else
				(*alst)->next = new;
		}
	}
}
