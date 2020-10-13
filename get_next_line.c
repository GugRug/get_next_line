/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 04:04:34 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/13 06:11:12 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_utils.c"

#define BUFFER_SIZE 3

int	

int	get_next_line(int fd, char **line)
{
	static char	s_line;
	char	*buf;
	int	rd, i_test;
	
	if (fd < 0 || !(line) || BUFFER_SIZE < 1)
		return (-1);
	buf = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!(s_line))
		s_line = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char));
	//LIMPAR S_LINE PARA COLOCAR BUSCAR POR \N COMO CONDICAO DO LOOPING
	while (rd = read(fd, buf, BUFFER_SIZE > 0) && i_test > 10)
	{
		if ()
		i_test++;
		if(ft_strchr(buf, '\n'))
			break;
	}
	
	//tests
	// char c = rd + '0';
	// write(1, &c, 1);	
	write(1, "\n--\n", 4);
	return(0);
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
