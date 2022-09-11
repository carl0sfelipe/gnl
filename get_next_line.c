/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 03:13:48 by csiqueir          #+#    #+#             */
/*   Updated: 2022/09/11 03:18:05 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_until_bar_n(int fd, char *static_str)
{
	char	*buff;
	int		red_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	red_bytes = 1;
	while (!ft_strchr(static_str, '\n') && red_bytes > 0)
	{
		red_bytes = read(fd, buff, BUFFER_SIZE);
		if (red_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[red_bytes] = '\0';
		static_str = ft_strjoin(static_str, buff);
	}
	free(buff);
	return (static_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*static_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	static_str = read_until_bar_n(fd, static_str);
	if (!static_str)
		return (NULL);
	line = ft_get_line(static_str);
	static_str = get_remaining(static_str);
	return (line);
}
