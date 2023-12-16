/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:05:55 by fracurul          #+#    #+#             */
/*   Updated: 2023/12/16 18:32:54 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *s)
{
	char	*line;
	int		i;

	if (gnl_strchr(s, '\n'))
		i = gnl_strchr(s, '\n');
	else
		i = gnl_strlen(s);
	line = (char *)gnl_calloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n' && s[i])
		line[i] = '\n';
	return (line);
}

char	*ft_readgnl(int fd, char *s)
{
	char	*bufferword;
	int		checkread;

	checkread = 1;
	bufferword = (char *)gnl_calloc(BUFFER_SIZE + 1);
	while (!bufferword)
		return (free(bufferword), NULL);
	while (checkread > 0)
	{
		checkread = read(fd, bufferword, BUFFER_SIZE);
		if (checkread == -1)
			return (free(bufferword), NULL);
		s = gnl_strjoin(s, bufferword);
		s[checkread] = '\0';
		if (gnl_strchr(s, '\n'))
			break ;
	}
	free(bufferword);
	return (s);
}

char	*ft_buffer_ud(char *s)
{
	char	*excessbuffer;
	int		i;
	int		j;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if(!s[i])
		return (free(s), NULL);
	i = gnl_strchr(s, '\n');
	j = gnl_strlen(s) - i;
	excessbuffer = (char *)gnl_calloc(j + 1);
	if (!excessbuffer)
		return (free(s), free(excessbuffer), NULL);
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
