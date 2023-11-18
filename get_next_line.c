/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:05:55 by fracurul          #+#    #+#             */
/*   Updated: 2023/11/18 18:42:50 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *s)
{
	char	*line;
	int		i;

	i = ft_strchrgnl(s, '\n');
	line = (char *)ft_callocgnl(i + 1, 1);
	if (!line)
		return (free(line), NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		line[i] = '\n';
	return(line);
}
char	*ft_readgnl(int fd, char *s)
{
	char	*bufferword;
	int		checkread;


	checkread = 1;
	bufferword = (char *)ft_callocgnl(BUFFER_SIZE + 1, 1);
	while (!bufferword)
		return (free(bufferword), bufferword);
	while (checkread > 0)
	{
		checkread = read(fd, bufferword, BUFFER_SIZE);
		if (checkread == -1)
			return (free(bufferword), NULL);
		s = ft_gnljoin(s, bufferword);
		if (ft_strchrgnl(s, '\n'))
			break ;
	}
	free(bufferword);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*s = NULL;
	char		*aux = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s = ft_readgnl(fd, s);
	aux = ft_get_line(s);
	s = ft_buffer_ud(s);
	close(fd);
	return (aux);
}