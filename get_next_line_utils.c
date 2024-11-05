/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:45:11 by ipersids          #+#    #+#             */
/*   Updated: 2024/11/05 13:53:49 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int ch)
{
	unsigned int	i;
	char			*res;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
		{
			res = (char *)(str + i);
			return (res);
		}
		i++;
	}
	if (ch == 0)
	{
		res = (char *)(str + i);
		return (res);
	}
	return (0);
}

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(str);
	copy = (char *)malloc(len + 1);
	if (!copy)
		return (0);
	ft_memcpy(copy, str, len);
	copy[len] = '\0';
	return (copy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*res;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = (char *) malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!res)
		return (0);
	ft_memcpy(res, s1, s1_len);
	ft_memcpy(&(res[s1_len]), s2, s2_len);
	res[s1_len + s2_len] = '\0';
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	char		*dest;
	const char	*src;
	size_t		i;

	dest = destination;
	src = source;
	i = 0;
	if (num == 0)
		return (destination);
	while (i < num)
	{
		dest[i] = src[i];
		i++;
	}
	return ((void *)dest);
}
