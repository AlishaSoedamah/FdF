/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:53:38 by ksoedama          #+#    #+#             */
/*   Updated: 2024/10/16 13:55:19 by ksoedama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				s_len;
	unsigned char	c_tmp;

	s_len = ft_strlen(s);
	c_tmp = (unsigned char)c;
	while (s_len >= 0)
	{
		if (s[s_len] == c_tmp)
			return ((char *)s + s_len);
		s_len--;
	}
	return (NULL);
}
