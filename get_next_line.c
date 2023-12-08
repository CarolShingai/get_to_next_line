/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:49:02 by cshingai          #+#    #+#             */
/*   Updated: 2023/12/08 20:31:13 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


char	*get_next_line(int fd)
{
	char		*line_to_return;
	char		*line;
	static char	*remainder;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	line = ft_read_line(&remainder, fd);
	if (!line)
		return (NULL);
	line_to_return = ft_build_line(line);
	free(line);
	return (line_to_return);
	if (*line_to_return == '\0' && *remainder == '\0')
	{
		free(line_to_return);
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	return (line_to_return);
}

char	*ft_read_line(char **remainder, int fd)
{
	char	content[BUFFER_SIZE + 1];
	char	*temp;
	ssize_t	char_read;

	char_read = 1;
	while (char_read != 0)
	{
		char_read = read(fd, content, BUFFER_SIZE);
		if (char_read < 0 || (!char_read && !ft_strlen(*remainder)))
			return (NULL);
		content[char_read] = 0;
		temp = ft_strjoin(*remainder, content);
		free(*remainder);
		*remainder = temp;
		if (!temp)
			return (NULL);
		if (ft_strchr(*remainder, '\n'))
			break ;
	}
	return (ft_strdup(*remainder));
}

char	*ft_build_line(char *line)
{
	int		index;

	if (ft_strchr(line, '\n'))
		index = ft_strchr(line, '\n') - line + 1;
	else
		index = ft_strlen(line);
	if (!index)
		return (NULL);
	return (ft_cpy(line, index));
}

void	get_after_newline(char **remainder)
{
	char	*temp;

	if (ft_strchr(*remainder, '\n'))
	{
		temp = ft_strdup(ft_strchr(*remainder, '\n') + 1);
		free(*remainder);
		*remainder = temp;
	}
	else
	{
		free(*remainder);
		*remainder = 0;
	}
}

// #include <fcntl.h>
// #include <stdio.h>
// int	main(void)
// {
// 	int	fd;
// 	char	*text_line;
// 	char	*lines;
// 	int		i = 0;

// 	fd = open("hello.txt", O_RDONLY);
// 	while (i < 1)
// 	{
// 		lines = get_next_line(fd);
// 		printf("%d |%s",i + 1, lines);
// 		free(lines);	// if (!s1)
// 	// 	return (ft_strdup((char *)s2));
// 	// if (!s2)
// 	// 	return(ft_strdup((char *)s1));
// 		i++;
// 	}
// 	close(fd);
// }