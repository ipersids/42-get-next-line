/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:24:22 by ipersids          #+#    #+#             */
/*   Updated: 2024/11/06 14:31:00 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>		// malloc(), free(), NULL macros
# include <unistd.h>		// read(), sysconf(_SC_OPEN_MAX) = 1024
# include <limits.h>		// Limits to manage BUFFER_SIZE, OPEN_MAX

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

/**
 * BUFFER_SIZE Memory Guard
 *
 * This guard checks the value of BUFFER_SIZE set at compile time 
 * to prevent errors related to buffer allocation.
 *
 * - If BUFFER_SIZE is <= 0, it undefines the macro, preventing 
 *   `get_next_line` from attempting to allocate an invalid (negative) 
 *   buffer size, which would disrupt program execution.
 * 
 * - If BUFFER_SIZE + 1 exceeds SIZE_MAX, it also undefines the macro to 
 *   avoid excessive memory allocation requests that could lead to 
 *   program instability or crashes.
 * 
 * - If BUFFER_SIZE is undefined after these checks, it is defined with 
 *   a default value of 100, simulating `getline` behavior.
 */
# ifdef BUFFER_SIZE
#  if BUFFER_SIZE <= 0
#   undef BUFFER_SIZE
#  endif
#  if BUFFER_SIZE >= SIZE_MAX
#   undef BUFFER_SIZE
#  endif
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);

/* -------------------------- Get Next Line Utils -------------------------- */

char	*ft_strchr(const char *str, int ch);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *destination, const void *source, size_t num);

#endif
