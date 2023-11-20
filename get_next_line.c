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

/*
1Path: find if there is a newline \n
2Path: Find how many char I have before \n
Put \0 in the string
*/
void	ft_create_list(t_list newlist, int fd)
{
	int char_read;
	char *buffer;
	while (!found_newline(*newlist))
	{
		buffer = (char *)malloc (BUFFER_SIZE + 1);
		if(!buffer)
			return ;
		char_read = read(fd, buffer, BUFFER_SIZE);	
	}
	if (!char_read)
	{
		free(buffer);
		return ;
	}
	buffer[char_read] = '\0';
	ft_add_newlist_to_list(newlist, buffer)
}

void	ft_add_newlist_to_list(t_list **list, char *buffer)
{
	t_list *new_node;
	t_list *last_node;
	last_node = ft_find_last_node(*list);
	new_node = malloc(sizeof (t_list));
	if (!new_node)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->content = buffer;
	new_node->next = NULL;
}

char	get_line(t_list list)
{
	int	strlen;
	char *next_str;
	if (!list)
		return (NULL);
	//str len until find the char \n
	strlen = len_to_newline(*list);
	next_str = malloc(strlen + 1);
	if (!next_str)
		return (NULL);
	//copiar str
	copy_str(list, next_str);
	return(next_str);
}

void	rearrange_list(t_list **list)
{
	t_list	last_node;
	t_list	clean_node;
	int	index;
	int	idx_all;
	char	*buffer;

	index = 0;
	idx_all = 0;
	buffer = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof (t_list));
	if (!buffer || !clean_node)
		return ;
	last_node = ft_find_last_node(*list);
	while (last_node->content[index] && last_node->content[index] != '\n')
		index++;
	while (last_node->content[index] && last_node->content[++index])
		buffer[idx_all++] = last_node->content[index];
	buffer[idx_all] = '\0';
	clean_node->content = buffer;
	clean_node->next = NULL;
	// clean the residual nodes
	free_nodes(list, clean_node, buffer);
}


char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;

	list = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	ft_create_list(&list, fd);
	if (!list)
		return (NULL);
	next_line = get_line(list);
	rearrange_list(list);
	return (next_line);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	char	*text_line;
	int		lines;

	lines = 1;
	fd = open("hello.txt", O_RDONLY);
	while (text_line = get_next_line(fd))
		printf("%d->%s\n", lines++, text_line);
	close(fd);
}
