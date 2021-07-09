/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 17:33:38 by mac               #+#    #+#             */
/*   Updated: 2020/05/20 15:35:55 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	end_index;
	size_t	index;

	end_index = ft_strlen(s);
	index = 0;
	if (s == 0)
		return (0);
	if (start >= end_index)
		return ((char *)ft_calloc(1, 1));
	substr = (char*)malloc(len + 1);
	if (substr)
	{
		s += start;
		while (s[index] && index < len)
		{
			substr[index] = s[index];
			index += 1;
		}
		substr[index] = '\0';
		return (substr);
	}
	else
		return (0);
}
