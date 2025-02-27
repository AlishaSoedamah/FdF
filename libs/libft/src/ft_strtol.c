/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:07:59 by ksoedama          #+#    #+#             */
/*   Updated: 2025/02/16 12:10:00 by ksoedama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdio.h>

static long	overflow(int sign, int *is_overflow)
{
	if (is_overflow != NULL)
		*is_overflow = 1;
	if (sign == 1)
		return (LONG_MAX);
	return (LONG_MIN);
}

static int	base_int(int c, int *digit)
{
	if (ft_isdigit(c))
		*digit = c - '0';
	else if (c >= 'a' && c <= 'z')
		*digit = c + 10 - 'a';
	else if (c >= 'A' && c <= 'Z')
		*digit = c + 10 - 'A';
	else
		return (1);
	return (0);
}

static void	set_endptr(char *ptr, char **end_ptr)
{
	if (end_ptr != NULL)
		*end_ptr = ptr;
}

static void	rm_color_prefix(char *s, int *sign, int *i)
{
	*sign = 1;
	while (ft_isspace(s[*i]))
		(*i)++;
	if (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
		{
			*sign = -1;
			(*i)++;
		}
	}
	if (ft_strncmp(s, "0x", 2) == 0)
		*i += 2;
}

long	ft_strtol(char *s, char **end_ptr, int *is_overflow, int base)
{
	int		i;
	long	res;
	int		digit;
	int		sign;

	sign = 0;
	i = 0;
	res = 0;
	if (is_overflow != NULL)
		*is_overflow = 0;
	rm_color_prefix(s, &sign, &i);
	while (s[i])
	{
		if (base_int(s[i], &digit) || digit >= base)
			break ;
		if (res > (LONG_MAX - digit) / base)
		{
			set_endptr((char *)s, end_ptr);
			return (overflow(sign, is_overflow));
		}
		res = res * base + digit;
		i++;
	}
	set_endptr(&s[i], end_ptr);
	return (res * sign);
}
