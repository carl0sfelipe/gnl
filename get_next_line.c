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

char	*get_remaining(char *static_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (static_str[i] && static_str[i] != '\n')
		i++;
	if (!static_str[i])
	{
		free(static_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(static_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (static_str[i])
		str[j++] = static_str[i++];
	str[j] = '\0';
	free(static_str);
	return (str);
}

char	*ft_get_line(char *static_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!static_str[i])
		return (NULL);
	while (static_str[i] && static_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (static_str[i] && static_str[i] != '\n')
	{
		str[i] = static_str[i];
		i++;
	}
	if (static_str[i] == '\n')
	{
		str[i] = static_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*read_until_bar_n(int fd, char *static_str)
{
	char	*buff;
	int		bytes_red;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes_red = 1;
	while (!ft_strchr(static_str, '\n') && bytes_red > 0)
	{
		bytes_red = read(fd, buff, BUFFER_SIZE);
		if (bytes_red == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes_red] = '\0';
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
