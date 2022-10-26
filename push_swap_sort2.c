/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dida-sil <dida-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:40:06 by dida-sil          #+#    #+#             */
/*   Updated: 2022/10/26 13:40:07 by dida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		save_move(char **mem, char *mv, int8_t pref);
static char	*push_half(t_cdlist **lsta, t_cdlist **lstb, int n, int8_t pref);
char		*simple_sort(t_cdlist **lst, t_cdlist **aux, int n, int8_t pref);
char		*gsort(t_cdlist **lsta, t_cdlist **lstb, int n, int8_t pref);

void	save_move(char **mem, char *mv, int8_t pref)
{
	ft_strjoin_ps(mem, mv, 0);
	if (pref >= 0)
		ft_strjoin_ps(mem, "a\n", 0);
	else
		ft_strjoin_ps(mem, "b\n", 0);
}

static char	*push_half(t_cdlist **lsta, t_cdlist **lstb, int n, int8_t pref)
{
	int			mid;
	int			pushed;
	char		*moves;
	t_cdlist	*temp;

	mid = findmidian(*lsta, n, 1, pref);
	pushed = 0;
	moves = NULL;
	temp = *lsta;
	while ((temp->content < mid && pref >= 0)
		|| (temp->content > mid && pref < 0))
		temp = temp->next;
	while (pushed < n / 2)
	{
		if (((*lsta)->content < mid && pref >= 0)
			|| ((*lsta)->content > mid && pref < 0))
		{
			save_move(&moves, top_push(lsta, lstb), -pref);
			++pushed;
		}
		else
			save_move(&moves, rotate_up(lsta), pref);
	}
	ft_strjoin_ps(&moves, optimal_traverse(lsta, &temp, pref), 1);
	return (moves);
}

char	*simple_sort(t_cdlist **lst, t_cdlist **aux, int n, int8_t pref)
{
	int			pushed;
	char		*moves;

	pushed = n / 2;
	moves = NULL;
	if (is_sorted(*lst, n, 1, pref) == pref)
		return (NULL);
	if (n == 2)
		swap_first2(lst);
	else if (n > 2)
	{
		push_half(lst, aux, n, pref);
		simple_sort(lst, aux, n - pushed, pref);
		simple_sort(aux, lst, pushed, -pref);
		while (pushed-- > 0)
			top_push(aux, lst);
	}
	if (moves)
		free(moves);
	moves = NULL;
	return (moves);
}

char	*gsort(t_cdlist **lsta, t_cdlist **lstb, int n, int8_t pref)
{
	int			pushed;
	char		*moves;

	if (n < 0 || n > ft_intdlst_size(*lsta))
		n = ft_intdlst_size(*lsta);
	pushed = n / 2;
	moves = NULL;
	if (is_sorted(*lsta, n, 1, pref) == pref)
		return (NULL);
	if (n == 2)
		save_move(&moves, swap_first2(lsta), pref);
	else if (n > 2)
	{
		ft_strjoin_ps(&moves, push_half(lsta, lstb, n, pref), 1);
		if (pref >= 0)
			ft_strjoin_ps(&moves, gsort(lsta, lstb, n - pushed, pref), 1);
		ft_strjoin_ps(&moves, gsort(lstb, lsta, pushed, -pref), 1);
		if (pref < 0)
			ft_strjoin_ps(&moves, gsort(lsta, lstb, n - pushed, pref), 1);
		while (pushed-- > 0)
			save_move(&moves, top_push(lstb, lsta), pref);
	}
	return (moves);
}
