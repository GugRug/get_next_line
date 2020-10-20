/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:05:10 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/20 11:27:52 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

/*
** gnl
*/
int		get_next_line(int fd, char **line);
char	*ft_readbuf(int fd, int *r_fd);
char	*ft_justdoit(char *s_line, char **line, int *r_fd);
/*
** gnl Utils
*/
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_strchr_bn(char *s);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_strdel(char **s);
#endif
