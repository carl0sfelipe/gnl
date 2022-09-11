/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 03:13:57 by csiqueir          #+#    #+#             */
/*   Updated: 2022/09/11 03:13:58 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *static_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!static_str)
	{
		static_str = (char *)malloc(1 * sizeof(char));
		static_str[0] = '\0';
	}
	if (!static_str || !buff)
		return (NULL);
	str = malloc(1 * ((ft_strlen(static_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (static_str)
		while (static_str[++i] != '\0')
			str[i] = static_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(static_str) + ft_strlen(buff)] = '\0';
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
