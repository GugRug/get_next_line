/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 22:41:49 by hcastanh          #+#    #+#             */
/*   Updated: 2020/10/20 04:56:59 by gumartin         ###   ########.fr       */
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

	while(line)
	{
		printf("%s", line);
		printf("-----\n");
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
