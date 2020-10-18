/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 04:04:34 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/18 20:14:41 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 5

int	get_next_line(int fd, char **line)
{
	static char	*s_line;
	char	*buf;
	int	rd;
	
	if (fd < 0 || !(line) || BUFFER_SIZE < 1)
		return(-1);
	if (!(s_line))
	{
		s_line = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char*));
		ft_strclean(s_line, BUFFER_SIZE + 1);
	}
	buf = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char*));
	ft_strclean(buf, BUFFER_SIZE + 1);
	while ((ft_strchr(s_line, '\n') == NULL) && ((rd = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		s_line = ft_strjoin(s_line, buf);
		ft_strclean(buf, ft_strlen(buf));
	}
	s_line = ft_puts_line(s_line, line);
	free(buf);
	buf = NULL;
	if (rd >= 1)
		return (1);
	return (0);
}

char	*ft_puts_line(char *s_line, char **line)
{
	char	*temp;
	int	bn_c;
	int	i;
	
	bn_c = ft_strlen(s_line);
	i = 0;
	if (ft_strchr(s_line, '\n'))
		i = ft_strlen(ft_strchr(s_line, '\n'));
	bn_c -= i;
	*line = (char*)malloc((bn_c) * sizeof(char*));
	ft_strlcpy(*line, s_line, bn_c);
	temp = (char*)malloc((i + 1) * sizeof(char*));
	if (i > 0)
		ft_strlcpy(temp, &s_line[bn_c + 1], i + 1);
	else
		temp = &(s_line[bn_c]);
	free(s_line);
	s_line = NULL;
	return (temp);	
}


/*
TEST
*/

int	main(void)
{
	int	retorno = 1, fd = open("text.txt", 0);
	char *line;
	write(1, "gnl:\n", 5);
	
	get_next_line(fd, &line);
	while(line)
	{
		printf("-------\n");
		printf("Line: %s\n Size: %ld\n", line, ft_strlen(line));
		free(line);
		write(1, "----\n", 5);
		if (retorno <= 0)
			break;
		retorno = get_next_line(fd, &line);
	}
	close(fd);
	return(0);
}
