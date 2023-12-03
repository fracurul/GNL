/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:05:55 by fracurul          #+#    #+#             */
/*   Updated: 2023/12/03 18:56:37 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *s)
{
	char	*line;
	int		i;

	if (ft_strchrgnl(s, '\n'))
		i = ft_strchrgnl(s, '\n');
	else
		i = ft_strlengnl(s);
	line = (char *)ft_callocgnl(i + 1, 1);
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ft_readgnl(int fd, char *s)
{
	char	*bufferword;
	int		checkread;

	checkread = 1;
	bufferword = (char *)ft_callocgnl(BUFFER_SIZE + 1, 1);
	while (!bufferword)
		return (NULL);
	while (checkread > 0 || ft_strchrgnl(s, '\n'))
	{
		checkread = read(fd, bufferword, BUFFER_SIZE);
		if (checkread == -1)
			return (free(bufferword), NULL);
		if (checkread == 0)
			break ;
		s = ft_gnljoin(s, bufferword);
	}
	free(bufferword);
	return (s);
}

char	*ft_buffer_ud(char *s)
{
	char	*excessbuffer;
	int		i;
	int		j;

	if	(!s || !ft_strchrgnl(s, '\n'))
		return (free (s), NULL);
	i = ft_strchrgnl(s, '\n');
	j = ft_strlengnl(s) - i;
	excessbuffer = (char *)ft_callocgnl(j + 2, 1);
	if (!excessbuffer)
		return (free(s), NULL);
	j = 0;
	i++;
	while (s && s[i + j])
	{
		excessbuffer[j] = s[i + j];
		j++;
	}
	free(s);
	return (excessbuffer);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*aux;

	aux = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s = ft_readgnl(fd, s);
	if (s == NULL)
		return (NULL);
	aux = ft_get_line(s);
	s = ft_buffer_ud(s);
	return (aux);
}
