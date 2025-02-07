/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:35:48 by ksoedama          #+#    #+#             */
/*   Updated: 2024/10/24 13:38:00 by ksoedama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tmp;

	if (nmemb && size > __SIZE_MAX__ / nmemb)
		return (NULL);
	tmp = (void *)malloc(nmemb * size);
	if (tmp == NULL)
		return (NULL);
	ft_bzero(tmp, (nmemb * size));
	return (tmp);
}
