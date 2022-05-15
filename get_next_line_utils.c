/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 08:01:37 by owalsh            #+#    #+#             */
/*   Updated: 2022/05/15 17:09:43 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c > 256)
		c %= 256;
	while (s && *s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = malloc(sizeof(char) * (i + j + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = 0;
	return (str);
}

char	*ft_strndup(const char *s)
{
	char	*dup;
	int		i;
	// int		n;

	if (!s)
		return (NULL);
	// n = 0;
	// // while (s[n] != '\n')
	// // 	n++;
	// // n++;
	// while (s[n])
	// {
	// 	if (s[n] == '\n')
	// 	{
	// 		n++;
	// 		break;
	// 	}
	// 	n++;
	// }
	// printf("duplicates until %d bytes\n", n);
	i = ft_strlen(s);
	dup = malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		dup[i] = s[i];
		i++;
	}
	if (s && s[i] == '\n')
		dup[i] = s[i];
	i++;
	dup[i] = '\0';
	return (dup);
}
