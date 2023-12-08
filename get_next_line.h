/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:22:45 by cshingai          #+#    #+#             */
/*   Updated: 2023/12/07 21:29:28 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*ft_build_line(char *line);
char	*ft_read_line(char **remainder, int fd);
void	get_after_newline(char **remainder);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strdup(char *c);
char	*ft_cpy(char *line, int pos);
void	*ft_calloc(size_t n_element, size_t size);

#endif