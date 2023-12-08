/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:03:53 by cshingai          #+#    #+#             */
/*   Updated: 2023/12/08 16:50:04 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, int c)
{
	int	index;

	index = 0;
	while (str && str[index])
	{
		if (str[index] == (unsigned char)c)
		{
			return ((char *)&str[index]);
		}
		index++;
	}
	if ((unsigned char)c == str[index])
		return ((char *) &str[index]);
	return (0);
}

char	*ft_strdup(char *c)
{
	char	*temp;
	int		index;
	int		len_c;

	index = 0;
	len_c = ft_strlen(c);
	temp = ft_calloc((len_c + 1), sizeof(char));
	if (temp == 0)
		return (0);
	while (c[index])
	{
		temp[index] = c[index];
		index++;
	}
	return (temp);
}
int	ft_strlen(const char *str)
{
	int	index;

	index = 0;
	while (str && str[index])
		index++;
	return (index);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int	idx1;
	int	idx2;
	int		size_line;
	char	*new_s;

	idx1 = -1;
	idx2 = -1;
	size_line = ft_strlen(s1) + ft_strlen(s2);
	new_s = ft_calloc((size_line + 1), sizeof(char));
	if (!new_s)
		return (NULL);
	while (s1 && s1[++idx1])
		new_s[idx1] = s1[idx1];
	while (s2 && s2[++idx2])
		new_s[idx1 + idx2] = s2[idx2];
	return (new_s);
}

char	*ft_cpy(char *line, int pos)
{
	char	*line_to_return;
	int		i;

	i = 0;
	if (!line || pos < 0)
		return (NULL);
	line_to_return = ft_calloc(sizeof(char), (pos + 1));
	if (!line_to_return)
		return (NULL);
	while (line && line[i] && i < pos)
	{
		line_to_return[i] = line[i];
		i++;
	}
	return (line_to_return);
}
void	*ft_calloc(size_t n_element, size_t size)
{
	void	*temp;
	size_t		total;
	size_t		index;

	index = 0;
	total = size * n_element;
	if ((size * n_element != 0) && (n_element * size) / size != n_element)
		return (0);
	temp = malloc (total);
	if (temp != 0)
		{
			while (index < total)
			{
				((unsigned char *)temp)[index] = '\0';
				index++;
			}
		}
	return (temp);
}