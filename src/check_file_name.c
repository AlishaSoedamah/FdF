/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:44:08 by ksoedama          #+#    #+#             */
/*   Updated: 2025/02/07 10:06:37 by ksoedama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <string.h>

int	check_name(char **av)
{
	int		len;
	char	*start;

	len = ft_strlen(av[1]);
	if (len < 4)
		return (1);
	start = &av[1][len - 4];
	if (ft_strncmp(start, ".fdf", 4) != 0)
		return (1);
	return (0);
}
