/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_optmization.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dida-sil <dida-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:39:29 by dida-sil          #+#    #+#             */
/*   Updated: 2022/10/26 13:39:30 by dida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		shiftleft(char *b, size_t len);
static int8_t	merge_ops_helper2(char *str1, char *mv1, char *str2, char *mv2);
static int8_t	merge_ops_helper(char *str, char *mv1, char *mv2, char *mid);
void			merge_ops(char *str);
char			*optimal_traverse(t_cdlist **start, t_cdlist **end,
					int8_t pref);

static void	shiftleft(char *b, size_t len)
{
	size_t	pos;

	pos = 0;
	while (b[pos] && pos < len)
		++pos;
	if (pos != len)
		len = pos;
	pos = 0;
	while (b[pos + len])
	{
		b[pos] = b[pos + len];
		pos++;
	}
	b[pos] = 0;
}

static int8_t	merge_ops_helper2(char *str1, char *mv1, char *str2, char *mv2)
{
	shiftleft(str2, ft_strlen(mv2));
	if (ft_strlen(mv1) == ft_strlen(mv2) && *mv1 != 'p')
		*(str1 + ft_strlen(mv1) - 2) = *str1;
	else
		shiftleft(str1, ft_strlen(mv1));
	return (1);
}

static int8_t	merge_ops_helper(char *str, char *mv1, char *mv2, char *mid)
{
	int		start;
	int		glider;
	int8_t	flag;

	start = -1;
	flag = 0;
	while (str[++start])
	{
		if (ft_strncmp(&str[start], mv1, ft_strlen(mv1)) == 0)
		{
			glider = start + 2;
			while (str[glider] && !ft_strchr(mid, str[glider])
				&& ft_strncmp(&str[glider], mv2, ft_strlen(mv2)))
			{
				if (str[glider] == 'r' && str[glider + 1] == 'r')
					++glider;
				++glider;
			}
			if (ft_strncmp(&str[glider], mv2, ft_strlen(mv2)) == 0)
				flag = merge_ops_helper2(&str[start], mv1, &str[glider], mv2);
		}
		if (str[start] == 'r' && str[start + 1] == 'r')
			++start;
	}
	return (flag);
}

void	merge_ops(char *str)
{
	int8_t	flag;

	flag = 1;
	while (flag)
	{
		flag = 0;
		flag += merge_ops_helper(str, "pa\n", "pb\n", "rs");
		flag += merge_ops_helper(str, "pb\n", "pa\n", "rs");
		flag += merge_ops_helper(str, "rra\n", "ra\n", "ps");
		flag += merge_ops_helper(str, "ra\n", "rra\n", "ps");
		flag += merge_ops_helper(str, "rb\n", "rrb\n", "ps");
		flag += merge_ops_helper(str, "rrb\n", "rb\n", "ps");
		flag += merge_ops_helper(str, "ra\n", "rb\n", "pb");
		flag += merge_ops_helper(str, "rb\n", "ra\n", "pa");
		flag += merge_ops_helper(str, "sa\n", "sb\n", "pb");
		flag += merge_ops_helper(str, "sb\n", "sa\n", "pa");
		flag += merge_ops_helper(str, "rra\n", "rrb\n", "pb");
		flag += merge_ops_helper(str, "rrb\n", "rra\n", "pa");
	}
}

char	*optimal_traverse(t_cdlist **start, t_cdlist **end, int8_t pref)
{
	int			len;
	int			count;
	t_cdlist	*temp;
	char		*moves;

	len = ft_intdlst_size(*start);
	count = 0;
	temp = *start;
	moves = NULL;
	while (temp != *end)
		temp = temp->prev + (++count * 0);
	while (*start != *end)
	{
		if (2 * count <= len)
		{
			rotate_down(start);
			save_move(&moves, "rr", pref);
		}
		else
			save_move(&moves, rotate_up (start), pref);
	}
	return (moves);
}
