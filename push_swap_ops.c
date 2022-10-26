/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dida-sil <dida-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:39:18 by dida-sil          #+#    #+#             */
/*   Updated: 2022/10/26 13:39:19 by dida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*swap_first2(t_cdlist **lst);
char	*rotate_down(t_cdlist **lst);
char	*rotate_down(t_cdlist **lst);
char	*top_push(t_cdlist **src, t_cdlist **dst);

char	*swap_first2(t_cdlist **lst)
{
	int	temp;

	if (!(lst && *lst && (*lst)->next != *lst))
		return ("");
	temp = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = temp;
	return ("s");
}

char	*rotate_up(t_cdlist **lst)
{
	if (!(lst && *lst && (*lst)->next != *lst))
		return ("");
	*lst = (*lst)->next;
	return ("r");
}

char	*rotate_down(t_cdlist **lst)
{
	if (!(lst && *lst && (*lst)->prev != *lst))
		return ("");
	*lst = (*lst)->prev;
	return ("rr");
}

char	*top_push(t_cdlist **src, t_cdlist **dst)
{
	t_cdlist	*temp;
	t_cdlist	*skp;

	if (!(src && dst && *src))
		return ("");
	temp = *src;
	if (*src == (*src)->next)
		*src = NULL;
	else
	{
		skp = (*src)->prev;
		skp->next = (*src)->next;
		*src = (*src)->next;
		(*src)->prev = skp;
	}
	temp->next = NULL;
	temp->prev = NULL;
	ft_intdlstadd_front(dst, temp);
	return ("p");
}
