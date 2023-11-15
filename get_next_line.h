/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:22:45 by cshingai          #+#    #+#             */
/*   Updated: 2023/11/15 18:57:44 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
void *content;
struct s_list *next;
} t_list;

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);

#endif