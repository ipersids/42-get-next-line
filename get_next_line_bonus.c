/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:24:08 by ipersids          #+#    #+#             */
/*   Updated: 2024/11/07 12:13:34 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* --------------------- Support function prototypes ----------------------- */

static char	*get_line_from_buffer(char *buf, char *nl);
static char	*get_line_from_stream(char *temp_buf, char *buf, int fd, char *nl);
static char	*join_safe(char *allocated_str, char *static_buf, char *nl);

/* ---------------------------- Implementation ----------------------------- */

/**
 * @brief Get the next line from the file descriptor.
 * 
 * The get_next_line() function reads the content of the file descriptor `fd` 
 * one line at a time. Each call returns a string containing the next line 
 * read, including the newline character `\n` if one is present. The function 
 * manages subsequent calls to return each line in order from the file or 
 * standard input.
 * 
 * @param fd The file descriptor to read from.
 * 
 * @return char* Pointer to the next line read, including the terminating `\n` 
 * 				 character (if present).
 *               NULL: If there is nothing more to read, or if an error occurs 
 * 				 (such as an invalid file descriptor).
 * 
 */
char	*get_next_line(int fd)
{
	static char	buffer[OPEN_MAX][BUFFER_SIZE + 1];
	char		*buf;
	char		*nl;
	char		*temp_buf;

	if (fd == -1)
		return (NULL);
	buf = buffer[fd];
	nl = ft_strchr(buf, '\n');
	if (nl != 0)
		return (get_line_from_buffer(buf, nl));
	temp_buf = ft_strdup(buf);
	if (!temp_buf)
		return (NULL);
	return (get_line_from_stream(temp_buf, buf, fd, nl));
}

static char	*get_line_from_buffer(char *buf, char *nl)
{
	size_t	i;
	size_t	len;
	char	*res;

	len = nl - buf + 1;
	res = (char *) malloc((len + 1) * sizeof(char));
	if (!res)
	{
		buf[0] = '\0';
		return (NULL);
	}
	ft_memcpy(res, buf, len);
	res[len] = '\0';
	i = 0;
	while (nl[i + 1] != '\0')
	{
		buf[i] = nl[i + 1];
		i++;
	}
	buf[i] = '\0';
	return (res);
}

static char	*get_line_from_stream(char *temp_buf, char *buf, int fd, char *nl)
{
	ssize_t	bytes_read;
	char	*res;

	while (1)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(temp_buf), NULL);
		buf[bytes_read] = '\0';
		nl = ft_strchr(buf, '\n');
		if (nl != 0)
			return (join_safe(temp_buf, buf, nl));
		res = ft_strjoin(temp_buf, buf);
		free(temp_buf);
		if (!res)
			return (NULL);
		temp_buf = res;
		if (bytes_read == 0)
		{
			if (*temp_buf != '\0')
				return (temp_buf);
			return (free(temp_buf), NULL);
		}
	}
}

static char	*join_safe(char *allocated_str, char *static_buf, char *nl)
{
	char	*nl_buf;
	char	*res;

	nl_buf = get_line_from_buffer(static_buf, nl);
	if (!nl_buf)
	{
		free(allocated_str);
		static_buf[0] = '\0';
		return (NULL);
	}
	res = ft_strjoin(allocated_str, nl_buf);
	free(allocated_str);
	free(nl_buf);
	if (!res)
	{
		static_buf[0] = '\0';
		return (NULL);
	}
	return (res);
}
