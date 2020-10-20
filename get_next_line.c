/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 04:04:34 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/20 04:47:03 by gumartin         ###   ########.fr       */
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
	if(ft_strchr_bn(s_line) == -1)
	{
		buf = ft_readbuf(fd, &r_fd); // return line
		s_line = ft_strjoin(s_line, buf);
		if (r_fd == -1)
		{
			ft_strdel(&buf);
			return 0;				//maybe return too soon, check later if realy there isnt nothing in s_line
		}
		ft_strdel(&buf);
	}
	s_line = ft_justdoit(s_line, line); // put in line, put rest in s_line
	return (1);
}

char	*ft_readbuf(int fd, int *r_fd)
{
	char	*buffer;
	char	*buffer_t;
	
	buffer_t = (char*)ft_calloc(BUFFER_SIZE + 1, sizeof(char*));
	buffer = (char*)ft_calloc(BUFFER_SIZE + 1, sizeof(char*));
	while((ft_strchr_bn(buffer) == -1 )&& (*r_fd = read(fd, buffer_t, BUFFER_SIZE)) > 0)
	{
		buffer = ft_strjoin(buffer, buffer_t);
		ft_strdel(&buffer_t);
		buffer_t = (char*)ft_calloc(BUFFER_SIZE + 1, sizeof(char*));
	}
	ft_strdel(&buffer_t);
	return (buffer);
}

char	*ft_justdoit(char *s_line, char **line)
{
	char	*temp;
	int		bn;
	int		len;
		
	bn = ft_strchr_bn(s_line);
	len = ft_strlen(s_line);
	if (bn >= 0)
	{
		temp = (char*)ft_calloc((len - bn) + 1, sizeof(char*));
		*line = (char*)ft_calloc((bn) + 1, sizeof(char*));
		ft_strlcpy(*line, s_line, bn);
		ft_strlcpy(temp, &s_line[bn + 1], len - bn);
	}
	else
	{
		ft_strlcpy(*line, s_line, len);
		if (*s_line == '\0')
		{
			*line = NULL;
		}
		temp = NULL;		
	}
	ft_strdel(&s_line);
	return (temp);
}
/*

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
*/