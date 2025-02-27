/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:01:48 by ksoedama          #+#    #+#             */
/*   Updated: 2025/02/15 12:50:21 by ksoedama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int		i;
	int		sign;
	int		res;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(s[i]))
	{
		res = (s[i] - '0') + (res * 10);
		i++;
	}
	return (res * sign);
}
