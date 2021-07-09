/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 17:57:47 by mac               #+#    #+#             */
/*   Updated: 2020/05/21 19:37:27 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#define INSIDE_WORD 1
#define OUTSIDE_WORD 0

static	int		number_of_strs(char *str, char delimiter)
{
	int	state;
	int	words_count;

	state = OUTSIDE_WORD;
	words_count = 0;
	while (*str)
	{
		if (*str == delimiter)
			state = OUTSIDE_WORD;
		else
		{
			if (state == OUTSIDE_WORD)
			{
				words_count += 1;
				state = INSIDE_WORD;
			}
		}
		str++;
	}
	return (words_count);
}

static	char	*move_ptr_to_new_word_start(char *str, char delimiter)
{
	while (*str && *str != delimiter)
		str++;
	while (*str && *str == delimiter)
		str++;
	return (str);
}

static	void	free_arr_of_strs(char **arr)
{
	int	index;

	index = 0;
	while (arr[index])
	{
		free(arr[index]);
		index += 1;
	}
	free(arr);
}

static	int		word_len(char *str, char delimiter)
{
	int	len;

	len = 0;
	while (*str && *str != delimiter)
	{
		str++;
		len++;
	}
	return (len);
}

char			**ft_split(char const *s, char c)
{
	char	**out_str;
	int		word_index;

	out_str = (char**)malloc((number_of_strs((char*)s, c) + 1) * sizeof(char*));
	if (out_str != 0)
	{
		while (*((char*)s) && *((char*)s) == c)
			s++;
		word_index = 0;
		while (*((char*)s))
		{
			out_str[word_index] = ft_substr((char*)s, 0, word_len((char*)s, c));
			if (out_str[word_index] == 0)
			{
				free_arr_of_strs(out_str);
				return (0);
			}
			s = (char*)move_ptr_to_new_word_start((char*)s, c);
			word_index += 1;
		}
		out_str[word_index] = 0;
		return (out_str);
	}
	else
		return (0);
}
