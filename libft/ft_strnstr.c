/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 15:41:47 by mac               #+#    #+#             */
/*   Updated: 2020/05/20 16:23:03 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = -1;
	while (*(haystack + ++i) && i < len)
		if (*(haystack + i) == *needle)
		{
			j = -1;
			while (*(needle + ++j) &&
					*(haystack + i + j) == *(needle + j) &&
					i + j < len)
				if (*(needle + j + 1) == '\0')
					return ((char *)&haystack[i]);
		}
	return (0);
}
