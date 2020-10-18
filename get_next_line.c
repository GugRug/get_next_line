/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 04:04:34 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/18 01:31:00 by gumartin         ###   ########.fr       */
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
	buf = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char*));								//malloc buf 1
	ft_strclean(buf, BUFFER_SIZE + 1);
	if (!(s_line))
	{
		s_line = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char*));						//malloc s_line 2
		ft_strclean(s_line, BUFFER_SIZE + 1);
	}
	while ((ft_strchr(s_line, '\n') == NULL) && ((rd = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		//printf("O valor de buf e: %s \n", buf);
		ft_putbuf(buf, &s_line);
	}
	printf("O valor de s_line ao entrar e: %s \n\n", s_line);
	ft_puts_line(&s_line, line);
	printf("O valor de s_line ao sair e: %s \n\n", s_line);
	free(buf);													//buf free 1	
	buf = NULL;
	free(s_line);												//s_line free 2
	s_line = NULL;
	return(0);
}

void	ft_putbuf(char *buf, char **s_line)
{
	char *bn;
	char *cpy;
	int p;
	
	if ((bn = ft_strchr(buf, '\n')))
		p = ft_strlen(buf) - ft_strlen(bn);
	else
		p = ft_strlen(buf);
	cpy = (char*)malloc((p + 1)* sizeof(char*));				//malloc cpy 3
	ft_strlcpy(cpy, buf, p + 1);
	*s_line = ft_strjoin(*s_line, cpy);
	free(cpy);													//cpy free 3
	cpy = NULL;
}

void	ft_puts_line(char **s_line, char **line)
{
	//put s_line in line, than free s_line pointing to '\n'
	int	i;
	int	pbn;
	
	i = 2;
	pbn = ft_strlen(*s_line);
	if (ft_strchr(*s_line, '\n'))
		pbn = ft_strlen(*s_line) - ft_strlen(ft_strchr(*s_line, '\n'));
	ft_strlcpy(*line, *s_line, pbn + 1);
	while (i < pbn)
	{
		(s_line)++;
		i++;
	}
		printf("O valor de s_line ao sair e: %s \n\n", *s_line);
}


/*
TEST
*/

int	main(void)
{
	int	i = 0, fd = open("text.txt", 0);
	char *line;
	write(1, "gnl:\n", 5);
	for(i = 0; i < 3; i++)
	{
		get_next_line(fd, &line); 
		printf("\nLine is: %s  ---\n", line);
	}
	write(1, "end\n", 4);
	close(fd);
	return(0);
}
