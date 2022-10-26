/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_comp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dida-sil <dida-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:39:02 by dida-sil          #+#    #+#             */
/*   Updated: 2022/10/26 13:39:03 by dida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cdlist	*nxtitem(t_cdlist *lst, int8_t direction);
void		ft_intdlstadd_sorted(t_cdlist **lst, t_cdlist *node, int8_t pref);
int8_t		repeated_num(t_cdlist *lst);

t_cdlist	*nxtitem(t_cdlist *lst, int8_t direction)
{
	if (direction >= 0)
		return (lst->next);
	return (lst->prev);
}

void	ft_intdlstadd_sorted(t_cdlist **lst, t_cdlist *node, int8_t pref)
{
	t_cdlist	*t;

	if (!(lst && *lst != NULL))
	{
		if (lst)
			ft_intdlstadd_front(lst, node);
		return ;
	}
	t = *lst;
	while (((pref < 0) ^ (node->content >= t->content)) && ((t->next) != *lst))
		t = t->next;
	if (((pref < 0) ^ (node->content >= t->content)))
		t = *lst;
	else if (t == *lst)
	{
		ft_intdlstadd_front(lst, node);
		return ;
	}
	ft_intdlstadd_front(&t, node);
}

int8_t	repeated_num(t_cdlist *lst)
{
	t_cdlist		*temp_i;
	t_cdlist		*temp_j;

	if (!lst)
		return (0);
	temp_i = lst;
	while (temp_i->next != lst)
	{
		temp_j = temp_i->next;
		while (temp_j != lst)
		{
			if (temp_i->content == temp_j->content)
				return (1);
			temp_j = temp_j->next;
		}
		temp_i = temp_i->next;
	}
	return (0);
}
