/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:09:07 by fracurul          #+#    #+#             */
/*   Updated: 2023/11/25 18:43:32 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlengnl(const char *s)
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

void	*ft_callocgnl(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(count * size);
	if (!str)
		return (str);
	while (i < count)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char	*ft_gnljoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		size1;
	int		size2;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	size1 = ft_strlengnl(s1);
	size2 = ft_strlengnl(s2);
	str = (char *)ft_callocgnl((size1 + size2) + 1, 1);
	if (!str)
		return (free(str), NULL);
	i = -1;
	j = -1;
	while (++i < size1)
		str[i] = s1[i];
	while (++j < size2)
		str[i + j] = s2[j];
	return (free(s1), str);
}

int	ft_strchrgnl(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == c)
		return (i);
	return (0);
}

char	*ft_buffer_ud(char *s)
{
	char	*excessbuffer;
	int		i;
	int		j;

	i = ft_strchrgnl(s, '\n');
	j = ft_strlengnl(s) - i;
	excessbuffer = (char *)ft_callocgnl(j + 1, 1);
	if (!excessbuffer)
		return (free(excessbuffer), NULL);
	j = 0;
	while (excessbuffer[j])
	{
		excessbuffer[j] = s[i + j];
		j++;
	}
	return (excessbuffer);
}
