/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:36:22 by ksoedama          #+#    #+#             */
/*   Updated: 2024/10/24 14:17:41 by ksoedama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *d, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*tmp_d;
	const unsigned char	*tmp_src;

	i = 0;
	tmp_d = (unsigned char *)d;
	tmp_src = (const unsigned char *)src;
	if (n == 0 || d == src)
		return (d);
	while (i < n)
	{
		tmp_d[i] = tmp_src[i];
		i++;
	}
	return (d);
}
