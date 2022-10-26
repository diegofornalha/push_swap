/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dida-sil <dida-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:40:24 by dida-sil          #+#    #+#             */
/*   Updated: 2022/10/26 13:40:24 by dida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_strlen(const char *s);
int		ft_strjoin_ps(char **prestr, char *sufstr, int8_t freesuf);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

int	ft_strlen(const char *s)
{
	int	len;

	if (s == NULL)
		return (0);
	len = -1;
	while (s[++len])
		;
	return (len);
}

int	ft_strjoin_ps(char **prestr, char *sufstr, int8_t freesuf)
{
	int		i1;
	int		i2;
	char	*fullstr;

	i1 = 0;
	i2 = 0;
	fullstr = (char *)malloc(ft_strlen(*prestr) + ft_strlen(sufstr) + 1);
	if (fullstr == NULL)
		return (0);
	while (*prestr && (*prestr)[i1])
	{
		fullstr[i1] = (*prestr)[i1];
		++i1;
	}
	while (sufstr && sufstr[i2])
		fullstr[i1++] = sufstr[i2++];
	fullstr[i1] = 0;
	if (*prestr)
		free (*prestr);
	if (freesuf)
		free (sufstr);
	*prestr = fullstr;
	return (1);
}

char	*ft_strchr(const char *s, int c)
{
	int	pos;

	pos = 0;
	c = (unsigned char) c;
	while (s[pos])
	{
		if (s[pos] == c)
			return ((char *)&(s[pos]));
		pos++;
	}
	if (s[pos] == c)
		return ((char *)&(s[pos]));
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	pos;

	pos = 0;
	if (!n)
		return (0);
	while (pos < (n - 1) && s1[pos] && s2[pos] && (unsigned char)s1[pos]
		== (unsigned char)s2[pos])
		pos++;
	return ((unsigned char)s1[pos] - (unsigned char)s2[pos]);
}

int	o_atoi(char **str, int8_t *flag)
{
	int				sign;
	unsigned long	num;

	sign = 1;
	num = 0;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	if (**str < '0' || **str > '9')
		(*flag)++;
	while (**str >= '0' && **str <= '9' && !(*flag))
	{
		num = num * 10 + **str - '0';
		if ((num >> 31) && !(sign == -1 && ((num - 1) >> 31 == 0)))
			(*flag)++;
		(*str)++;
	}
	return (num * sign);
}
