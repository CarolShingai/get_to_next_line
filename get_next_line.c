/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:30:36 by cshingai          #+#    #+#             */
/*   Updated: 2023/11/15 19:13:53 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	size_t	num;
	int		r;
	t_list	list;
	t_list	new_list;

	num = 2;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	r = read(fd, buffer, BUFFER_SIZE);
	list.content = buffer;
	list.next = 0;
	while (r > 0)
	{
		printf("buffer atual:%s\n", buffer);
		r = read(fd, buffer, BUFFER_SIZE);
		new_list.content = r;
		list.next = &new_list;
		new_list.next = 0;
	}
	buffer[r] = '\0';
	// printf("Esse é o read:%d\n", r);
	// printf("O que está armazenado no buffer:%s\n", buffer);
	if (fd < 0)
		return (0);
	// while (buffer[index] && num <= buffer)
	// 	index++;

	return (buffer);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	char	*palavras;

	fd = open("hello.txt", O_RDONLY);
	palavras = get_next_line(fd);
	// printf("Isso aqui é o fd:%d\n", fd);
	// printf("O que está sendo printado:%s\n", palavras);
	close(fd);
}
