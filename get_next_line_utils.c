/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:28:14 by cshingai          #+#    #+#             */
/*   Updated: 2023/11/15 18:57:28 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	len_to_newline(t_list *list)
{
	int index;
	int	len;

	len = 0;
	while (list)
	{
		index = 0;
		while (list->content[index])
		{
			if (list->content[index] == '\n')
			{
				++len;
				return (len);
			}
			++index;
			++len;
		}
		list = list->next;
	}
	return (len);
}


//after found newline is necessary store part of the buffer
void	copy_str(t_list *list, char *str)
{
	int	index;
	int	idx_all;

	idx_all = 0;
	while (list)
	{
		index = 0
		while (list->content[index])
		{
			if (list->content[index] == '\n')
			{
				str[idx_all++] = '\n'
				str[idx_all] = '\0'
				return ;
			}
			str[idx_all++] = list->content[index++]; 
		}
		list = list->next;
	}
	str[idx_all] = '\0';
}

void	free_nodes(t_list list, t_list clean_node, char *buffer)
{
	t_list temp;
	if (!list)
		return ;
	while (*list)
	{
		temp = *list->next;
		free((*list)->content);
		free(*list);
		*list = temp;
	}
	*list = NULL;
	if (clean_node->content[0])
		*list = clean_node;
	else
	{
		free(buffer);
		free(clean_node);
	}
}