/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 08:01:37 by owalsh            #+#    #+#             */
/*   Updated: 2022/05/16 17:46:44 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
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

char	*clean_line(char **line, char *buf)
{
	int		i;
	int		j;
	int		nl;
	char	*clean;

	i = 0;
	while ((*line)[i])
	{
		if ((*line)[i] == '\n')
			break;
		i++;
	}
	clean = malloc(sizeof(char) * (i + 2));
	if (!clean)
		return (NULL);
	j = 0;
	while (j < (i + 1))
	{
		clean[j] = (*line)[j];
		j++;
	}
	clean[j] = '\0';
	free(*line);
	nl = ft_strchr(buf, '\n');
	j = 0;
	if (nl)
	{
		while (buf[nl + 1 + j])
		{
			buf[j] = buf[nl + 1 + j];
			j++;
		}
	}
	buf[j] = 0;
	return (clean);
}

char	*ft_strdup_untilnl(char *s)
{
	char	*dup;
	int		i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	dup = malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\n')
		{
			dup[i] = s[i];
			i++;
			break;
		}
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
