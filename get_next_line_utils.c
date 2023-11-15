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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	idx1;
	size_t	idx2;
	char	*new_s;

	idx1 = 0;
	idx2 = 0;
	if (s1[idx1] == '\0' && s2[idx2] == '\0')
		return (ft_strdup(""));
	new_s = (char *)malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!new_s)
		return (NULL);
	while (s1[idx1])
	{
		new_s[idx1] = s1[idx1];
		idx1++;
	}
	while (s2[idx2])
	{
		new_s[idx1 + idx2] = s2[idx2];
		idx2++;
	}
	new_s[idx1 + idx2] = '\0';
	return (new_s);
}