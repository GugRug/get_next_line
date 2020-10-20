/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 04:04:34 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/20 00:24:54 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	*s_line;
	char		*buf;
	int			rd;

	if (fd < 0 || !(line) || BUFFER_SIZE < 1)
		return(-1);
	buf = (char*)ft_calloc(BUFFER_SIZE + 1, sizeof(char*));
	rd = read(fd, buf, BUFFER_SIZE);
	if (!(s_line))
	{
		if (rd == 0)
		{
			*line = (char*)ft_calloc(1, sizeof(char*));
			**line = '\0';
			free(buf);
			return (0);
		}
		s_line = (char*)ft_calloc(BUFFER_SIZE + 1, sizeof(char*));
	}
	while (rd)
	{
		s_line = ft_strjoin(s_line, buf);
		ft_strclean(buf, ft_strlen(buf));					//delete it
		rd = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	buf = NULL;
	s_line = ft_puts_line(s_line, line);
	if (*s_line == '\0')
	{
		return (0);
	}
	return (1);
}

char	*ft_puts_line(char *s_line, char **line)
{
	char	*temp;
	int	bn_c;
	int	i;
	
	bn_c = ft_strlen(s_line);
	i = 0;
		
	if (ft_strchr(s_line, '\n'))
	{
		i = ft_strlen(ft_strchr(s_line, '\n'));
		bn_c -= i;
		s_line[bn_c] = '\0';
	}
	*line = (char*)ft_calloc((bn_c + 1), sizeof(char*));
	ft_strlcpy(*line, s_line, bn_c + 1);
	temp = (char*)ft_calloc((i + 1), sizeof(char*));
	if (i > 0)
		ft_strlcpy(temp, &s_line[bn_c +1], i + 1);
	else
		temp = &(s_line[bn_c]);
	free(s_line);
	s_line = NULL;
	return (temp);
}
