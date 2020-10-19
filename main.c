/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 22:41:49 by hcastanh          #+#    #+#             */
/*   Updated: 2020/10/19 00:07:50 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int			fd;
	int			retorno;
	char		*line;

	fd = open("./text.txt", O_RDONLY);
	retorno = get_next_line(fd, &line);
	printf("Buffer Size is:%d and fd is:%d\n",(int)BUFFER_SIZE, fd);

	while(line)
	{
		printf("%s\n", line);
		write(1,"-----\n", 6);
		free(line);
		if (retorno <= 0)
			break;
		retorno = get_next_line(fd, &line);
	}
	switch (retorno)
	{
		case -1:
			printf("Arquivo terminou com erro\n");
			break;
		case 0:
			printf("PROGRAMA TERMINOU DE MANEIRA CORRETA.\n");
			break;
		case 1:
			printf("Arquivo não foi lido por completo.\n");
			break;
	}
	close (fd);
	return (retorno);
}
