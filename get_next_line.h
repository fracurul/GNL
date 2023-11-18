/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:08:11 by fracurul          #+#    #+#             */
/*   Updated: 2023/11/18 18:39:44 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

void	*ft_callocgnl(size_t count, size_t size);
char	*get_next_line(int fd);
char	*ft_gnljoin(char *s1, char *s2);
char	*ft_buffer_ud(char *s);
char	*ft_get_line(char *s);
int		ft_strchrgnl(char *s, char c);
int		ft_strlengnl(const char *s);

#endif