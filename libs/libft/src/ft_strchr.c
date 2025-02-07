/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:52:59 by ksoedama          #+#    #+#             */
/*   Updated: 2024/10/16 13:54:52 by ksoedama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	c_tmp;

	i = 0;
	c_tmp = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == c_tmp)
			break ;
		i++;
	}
	if (c_tmp == s[i])
		return ((char *)s + i);
	return (NULL);
}
