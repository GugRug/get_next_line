/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 04:04:34 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/20 09:54:52 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	*s_line;
	char		*buf;
	int			r_fd;

	if (fd < 0 || !(line) || BUFFER_SIZE < 1)
		return(-1);
	if (!s_line)
		s_line = (char*)ft_calloc(BUFFER_SIZE + 1, sizeof(char*));
	if (ft_strchr_bn(s_line) == -1)
	{
		buf = ft_readbuf(fd);
		s_line = ft_strjoin(s_line, buf);
		ft_strdel(&buf);
	}
	s_line = ft_justdoit(s_line, line, &r_fd);
	if (r_fd == -2)
		return (0);
	return (1);
}

char	*ft_readbuf(int fd)
{
	char	*buffer;
	char	*buffer_t;
	int		r_fd;

	buffer_t = (char*)ft_calloc(BUFFER_SIZE + 1, sizeof(char*));
	buffer = (char*)ft_calloc(BUFFER_SIZE + 1, sizeof(char*));
	while ((ft_strchr_bn(buffer) == -1 ) && (r_fd = read(fd, buffer_t, BUFFER_SIZE)) > 0)
	{
		buffer = ft_strjoin(buffer, buffer_t);
		ft_strdel(&buffer_t);
		buffer_t = (char*)ft_calloc(BUFFER_SIZE + 1, sizeof(char*));
	}
	ft_strdel(&buffer_t);
	return (buffer);
}

char	*ft_justdoit(char *s_line, char **line, int *r_fd)
{
	char	*temp;
	int		bn;
	int		len;

	temp = NULL;
	bn = ft_strchr_bn(s_line);
	len = ft_strlen(s_line);
	if (bn >= 0)
	{
		temp = (char*)ft_calloc((len - bn), sizeof(char*));
		*line = (char*)ft_calloc((bn) + 2, sizeof(char*));
		ft_strlcpy(*line, s_line, bn);
		ft_strlcpy(temp, &s_line[bn + 1], len - bn);
	}
	else if (s_line)
	{
		*line = (char*)ft_calloc((len) + 1, sizeof(char*));
		ft_strlcpy(*line, s_line, len + 1);
		*r_fd = -2;
	}
	else
		*line = NULL;
	ft_strdel(&s_line);
	return (temp);
}