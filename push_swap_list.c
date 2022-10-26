/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dida-sil <dida-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:39:13 by dida-sil          #+#    #+#             */
/*   Updated: 2022/10/26 13:39:14 by dida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cdlist	*ft_intdlstnew(int content);
void		ft_intdlstadd_front(t_cdlist **lst, t_cdlist *node);
void		ft_intdlstadd_back(t_cdlist **lst, t_cdlist *node);
void		ft_intdlstclear(t_cdlist **lst);
int			ft_intdlst_size(t_cdlist *lst);

t_cdlist	*ft_intdlstnew(int content)
{
	t_cdlist	*node;

	node = (t_cdlist *)malloc(sizeof(*node));
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	ft_intdlstadd_front(t_cdlist **lst, t_cdlist *node)
{
	if (!lst || !node)
		return ;
	if (*lst)
	{
		node->prev = (*lst)->prev;
		node->prev->next = node;
		node->next = *lst;
		node->next->prev = node;
		*lst = node;
		return ;
	}
	node->next = node;
	node->prev = node;
	*lst = node;
}

void	ft_intdlstadd_back(t_cdlist **lst, t_cdlist *node)
{
	t_cdlist	*back;

	if (!lst || !node)
		return ;
	if (*lst == NULL)
	{
		*lst = node;
		node->next = node;
		node->prev = node;
		return ;
	}
	back = (*lst)->prev;
	node->next = back->next;
	node->prev = back;
	back->next = node;
	(*lst)->prev = node;
}

void	ft_intdlstclear(t_cdlist **lst)
{
	t_cdlist	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		if ((*lst)->prev)
			(*lst)->prev->next = NULL;
		temp = *lst;
		*lst = (*lst)->next;
		free (temp);
	}
}

int	ft_intdlst_size(t_cdlist *lst)
{
	int			len;
	t_cdlist	*temp;

	len = 0;
	if (lst)
		++len;
	else
		return (len);
	temp = lst->next;
	while (temp != lst)
	{
		++len;
		temp = temp->next;
	}
	return (len);
}
