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
void	ft_create_list(t_list newlist, int fd);
void	ft_add_newlist_to_list(t_list **list, char *buffer);
void	copy_str(t_list *list, char *str);
void	free_nodes(t_list list, t_list clean_node, char *buffer);
void	rearrange_list(t_list **list);
char	get_line(t_list list);
int     len_to_newline(t_list *list);

#endif