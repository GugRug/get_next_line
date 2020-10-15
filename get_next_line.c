/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 04:04:34 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/15 03:30:23 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_utils.c"

#define BUFFER_SIZE 3

int	get_next_line(int fd, char **line)
{
	static char	*s_line;
	char	*buf;
	int	rd, i_test;
	
	if (fd < 0 || !(line) || BUFFER_SIZE < 1)
		return (-1);
	buf = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char));								//malloc buf 1
	if (!(s_line))
		s_line = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char));						//malloc s_line 2 - no free
	//LIMPAR S_LINE PARA COLOCAR BUSCAR POR \N COMO CONDICAO DO LOOPING
	while (rd = read(fd, buf, BUFFER_SIZE > 0) && !(ft_strchr(s_line, '\n')) && i_test > 10)
	{
		ft_putbuf(buf, s_line);
		if ()
		i_test++;
		if(ft_strchr(s_line, '\n'))
			break;
	}
	
	free(buf);																			//buf free 1	
		
	
	//tests
	// char c = rd + '0';
	// write(1, &c, 1);	
	write(1, "\n--\n", 4);
	return(0);
}

void ft_putbuf(char *buf, char **s_line)
{
	char *bn;
	char *cpy;
	int p;

	if (bn = ft_strchr(buf, '\n'))
		p = buf - bn;
	else
		p = ft_strlen(buf);
	cpy = (char*)malloc((p + 1)* sizeof(char*));				//malloc cpy 3
	ft_strlcpy(cpy, buf, p);
	s_line = ft_strjoin(s_line, cpy);
	free(cpy);													//cpy free 3
}

void ft_puts_line(char *s_line, char **line)
{
	//put s_line in line, than free s_line pointing to '\n'
}


/*
TEST
*/

int	main(void)
{
	int	i = 0;
	char *line;
	write(1, "gnl:\n", 5);
	for(i = 0; i < 3; i++)
	{
		get_next_line(open("text.txt", 0), &line); 
		write(1, line, ft_strlen(line));
	}
	write(1, "\n--\n", 4); 		
	write(1, "end\n", 4);
	return(0);
}
