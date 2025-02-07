/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoedama <ksoedama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:32:57 by ksoedama          #+#    #+#             */
/*   Updated: 2025/01/24 15:44:36 by ksoedama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	read_to_line(int fd, char **line)
{
	char	*buffer;
	ssize_t	byte_size;

	byte_size = 0;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (-1);
	byte_size = read(fd, buffer, BUFFER_SIZE);
	while (byte_size > 0)
	{
		buffer[byte_size] = '\0';
		*line = gnl_strjoin(line, buffer);
		if (*line == NULL)
		{
			free(buffer);
			return (-1);
		}
		if (ft_strchr(*line, '\n'))
			break ;
		byte_size = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (byte_size);
}

static char	*fn_free_and_return(char **line)
{
	free(*line);
	*line = NULL;
	return (NULL);
}

static char	*fn_strtok(char **line, char ch)
{
	char	*out_line;
	char	*nl;
	size_t	line_len;

	if (*line == NULL)
		return (NULL);
	nl = ft_strchr(*line, ch);
	if (nl)
	{
		line_len = ft_strlen(*line);
		out_line = ft_substr(*line, 0, nl - *line + 1);
		if (out_line == NULL)
			return (fn_free_and_return(line));
		if ((*(*line + (nl - *line + 1)) != '\0'))
			ft_strlcpy(*line, *line + (nl - *line + 1), line_len + 1);
		else
			fn_free_and_return(line);
	}
	else
	{
		out_line = ft_strdup(*line);
		fn_free_and_return(line);
	}
	return (out_line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	ssize_t		byte_read;

	byte_read = 0;
	if (line == NULL || ft_strchr(line, '\n') == NULL)
		byte_read = read_to_line(fd, &line);
	if (byte_read < 0)
	{
		if (line != NULL)
		{
			free(line);
			line = NULL;
		}
		return (NULL);
	}
	return (fn_strtok(&line, '\n'));
}
