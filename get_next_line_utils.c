/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:09:07 by fracurul          #+#    #+#             */
/*   Updated: 2023/12/16 18:20:20 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	*gnl_calloc(size_t count)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(count);
	if (!str)
		return (str);
	while (i < count)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	int		i;
	int		size1;
	int		size2;
	char	*str;

	if (!s1)
		s1 = (char *)gnl_calloc(1);
	if(!s2)
		return (NULL);
	size1 = gnl_strlen(s1);
	size2 = gnl_strlen(s2);
	str = (char *)gnl_calloc((size1 + size2) + 1);
	if (!str)
		return (free(s1), NULL);
	i = -1;
	while (++i < size1)
		str[i] = s1[i];
	i = -1;
	while (++i < size2)
		str[i + size1] = s2[i];
	return (free(s1), str);
}

int	gnl_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == c)
		return (i);
	return (0);
}
