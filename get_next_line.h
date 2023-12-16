/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:08:11 by fracurul          #+#    #+#             */
/*   Updated: 2023/12/16 14:59:42 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

void	*gnl_calloc(size_t count);
char	*get_next_line(int fd);
char	*gnl_strjoin(char *s1, char *s2);
char	*ft_buffer_ud(char *s);
char	*ft_get_line(char *s);
int		gnl_strchr(char *s, char c);
int		gnl_strlen(const char *s);

#endif