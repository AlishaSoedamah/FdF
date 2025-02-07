/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:33:55 by ksoedama          #+#    #+#             */
/*   Updated: 2024/10/25 17:25:05 by ksoedama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	i = 0;
	dst_len = ft_strlen(dst);
	i = dst_len;
	src_len = ft_strlen(src);
	if (dstsize == 0 && dst == NULL)
		return (src_len);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	j = 0;
	while (src[j] && i < dstsize - 1)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}
