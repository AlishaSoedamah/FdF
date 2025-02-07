/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:07:59 by ksoedama          #+#    #+#             */
/*   Updated: 2025/02/05 19:21:58 by ksoedama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>


static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\r'
		|| c == '\f');
}

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

long	ft_strtol(char *s, char **end_ptr, int *is_overflow, int base)
{
	int		i;
	int		sign;
	long	res;
	int		digit;

	i = 0;
	sign = 1;
	res = 0;
	if (is_overflow != NULL)
		*is_overflow = 0;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '+' || s[i] == '-')
		if (s[i++] == '-')
			sign = -1;
	if (ft_strncmp(s, "0x", 2) == 0)
		i += 2;
	while (s[i])
	{
		base_int(s[i], &digit);
		if (res > (LONG_MAX - digit) / base)
		{
			set_endptr((char *)s, end_ptr);
			return (overflow(sign, is_overflow));
		}
		res = res * base + digit;
		i++;
	}
	return (set_endptr(&s[i], end_ptr), res * sign);
}
