/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 02:36:01 by bal-khan          #+#    #+#             */
/*   Updated: 2018/08/29 02:36:04 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

t_list	*ft_lstnew(void	const *content, size_t content_size)
{
	t_list	*node;
	void	*p;

	if ((node = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if ((p = ft_memalloc(content_size)) == NULL)
		return (NULL);
	node->content = (content == NULL) ? NULL :
		memcpy(p, content, content_size);
	node->content_size = (content == NULL) ? 0 : content_size;
	node->next = NULL;
	return (node);
}

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (lst && f)
	{
		f(lst);
		ft_lstiter(lst->next, f);
	}
}

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst && *del)
	{
		ft_lstdel(&((*alst)->next), del);
		ft_lstdelone(alst, del);
	}
}

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst != NULL && del != NULL)
	{
		del((*alst)->content, (*alst)->content_size);
		ft_memdel((void **)alst);
	}
}
