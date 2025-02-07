/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:06:17 by ksoedama          #+#    #+#             */
/*   Updated: 2025/01/28 17:55:50 by ksoedama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_strs(char const *s, char c)
{
	unsigned int	i;
	int				counter;
	int				flag;

	i = 0;
	counter = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] != c && flag == 0)
		{
			flag = 1;
			counter++;
		}
		else if (s[i] == c)
			flag = 0;
		i++;
	}
	return (counter);
}

static char	*ft_next_substr(char const **s, char c)
{
	const char	*start;
	int			len;

	len = 0;
	while (**s == c && **s != '\0')
		(*s)++;
	start = *s;
	while (**s != c && **s != '\0')
	{
		(*s)++;
		len++;
	}
	return (ft_substr(start, 0, len));
}

static void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}

static char	**ft_new_arr(int count_strs)
{
	char	**array_new;
	int		i;

	i = 0;
	array_new = (char **)malloc((count_strs + 1) * sizeof(char *));
	if (array_new == NULL)
		return (NULL);
	while (i <= count_strs)
		array_new[i++] = NULL;
	return (array_new);
}

char	**ft_split(char const *s, char c)
{
	int		count_subsrs;
	char	**array;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	count_subsrs = ft_count_strs(s, c);
	if (count_subsrs == 0)
		return (ft_new_arr(0));
	array = ft_new_arr(count_subsrs);
	if (array == NULL)
		return (NULL);
	while (i < count_subsrs)
	{
		array[i] = ft_next_substr(&s, c);
		if (array[i] == NULL)
		{
			ft_free(array);
			return (NULL);
		}
		i++;
	}
	return (array);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	*str = NULL;
// 	char	**ptr;
// 	int i;

// 	i = 0;
// 	printf("String: %s\n\n", str);
// 	ptr = ft_split(str, ',');
// 	while (ptr[i] != NULL)
// 	{
// 		printf("Substring index %i is: %s.\n", i, ptr[i]);
// 		i++;
// 	}
// 	free(ptr);
// 	return (0);
// }

// int main()
// {
// 	printf("%d", ft_count_strs("thsisfour,Hek,b,a", ','));
// }
