/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 17:39:14 by mac               #+#    #+#             */
/*   Updated: 2020/05/20 18:32:46 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int	is_valid(char ch, char *invalid_chars)
{
	while (*invalid_chars)
	{
		if (*invalid_chars == ch)
			return (FALSE);
		invalid_chars++;
	}
	return (TRUE);
}

static	int	idx_of_first_valid_ch(char *str, char *set)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (is_valid(str[index], set) == TRUE)
		{
			return (index);
		}
		index += 1;
	}
	return (index);
}

static	int	idx_of_last_valid_ch(char *str, char *set)
{
	int	index;

	index = ft_strlen(str);
	while (index--)
	{
		if (is_valid(str[index], set) == TRUE)
			return (index);
	}
	return (index);
}

static	int	valid_str_len(char *str, char *invalid_chars)
{
	int	first_valid_char_idx;
	int	last_valid_char_idx;
	int	len;

	first_valid_char_idx = idx_of_first_valid_ch(str, invalid_chars);
	last_valid_char_idx = idx_of_last_valid_ch(str, invalid_chars);
	len = last_valid_char_idx + 1 - first_valid_char_idx;
	return (len);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		out_str_len;
	char	*out_str;
	char	*empty_str;

	out_str_len = valid_str_len((char *)s1, (char *)set);
	if (out_str_len > 0)
	{
		out_str = (char*)malloc((out_str_len + 1) * sizeof(char));
		if (out_str)
		{
			s1 += idx_of_first_valid_ch((char *)s1, (char *)set);
			ft_strlcpy(out_str, (char *)s1, out_str_len + 1);
			return (out_str);
		}
		else
			return (0);
	}
	else
	{
		empty_str = ft_calloc(1, sizeof(char));
		if (empty_str)
			return (empty_str);
		else
			return (0);
	}
}
