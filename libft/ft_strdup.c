/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 17:29:52 by mac               #+#    #+#             */
/*   Updated: 2020/05/17 17:32:25 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	str_len;
	char	*output_str;

	str_len = ft_strlen(s1);
	output_str = (char*)malloc(str_len * sizeof(char) + 1);
	if (output_str)
	{
		ft_strlcpy(output_str, s1, str_len + 1);
		return (output_str);
	}
	else
	{
		errno = ENOMEM;
		return (0);
	}
}
