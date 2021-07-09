/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_applaying_prescision.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 16:08:07 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 15:43:41 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 40
#define NOT_SET -10
#define SUCCESS 1
#define NEW_LINE_WAS_READ 1
#define EOF_WAS_REACHED 0
#define ALL_REMAINDER_WAS_READ 0
#define ERROR -1

static	int	get_line_from_cache(char **remainder, char **line)
{
	char *nl_ptr;
	char *tmp;

	if ((nl_ptr = ft_strchr(*remainder, '\n')))
	{
		*nl_ptr = '\0';
		*line = ft_strdup(*remainder);
		tmp = *remainder;
		*remainder = ft_strdup(++nl_ptr);
		free(tmp);
	}
	else
		*line = ft_strdup(*remainder);
	if (!*line || !*remainder)
		return (ERROR);
	else
		return (nl_ptr ? NEW_LINE_WAS_READ : ALL_REMAINDER_WAS_READ);
}

static	int	refill_cache_from_fd_untill_nl(int fd, char **remainder)
{
	ssize_t	number_of_read_bytes;
	char	*buffer;
	char	*tmp;

	buffer = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (ERROR);
	while ((number_of_read_bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[number_of_read_bytes] = '\0';
		tmp = *remainder;
		if (!(*remainder = ft_strjoin(*remainder, buffer)))
			return (ERROR);
		free(tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	if (number_of_read_bytes < 0)
		return (ERROR);
	else
		return (SUCCESS);
}

int			get_next_line(int fd, char **line)
{
	static char *cache;
	int			result;

	if (!line || BUFFER_SIZE <= 0 || (!cache && !(cache = ft_strdup(""))))
		return (ERROR);
	result = NOT_SET;
	if (!(ft_strchr(cache, '\n')))
		result = refill_cache_from_fd_untill_nl(fd, &cache);
	if (result != ERROR)
		result = get_line_from_cache(&cache, line);
	if ((result == ERROR || result == EOF_WAS_REACHED))
	{
		free(cache);
		cache = NULL;
	}
	return (result);
}
