/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:29:16 by ksoedama          #+#    #+#             */
/*   Updated: 2024/10/25 17:18:56 by ksoedama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		j;
	int		i;

	i = 0;
	j = ft_strlen(s);
	dup = malloc(j + 1);
	if (dup == NULL)
		return (NULL);
	while (i < j)
	{
		dup[i] = s[i];
		i++;
	}
	dup[j] = '\0';
	return (dup);
}
