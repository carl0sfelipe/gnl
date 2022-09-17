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
