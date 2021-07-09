/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 17:35:42 by mac               #+#    #+#             */
/*   Updated: 2020/05/20 20:43:49 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *first, char const *second)
{
	size_t	first_len;
	size_t	second_len;
	char	*str_joined;
	size_t	i;

	first_len = first ? ft_strlen(first) : 0;
	second_len = second ? ft_strlen(second) : 0;
	str_joined = (char*)malloc((first_len + second_len + 1) * sizeof(char));
	i = 0;
	while (i < first_len)
	{
		str_joined[i] = first[i];
		i++;
	}
	while (i < first_len + second_len)
	{
		str_joined[i] = second[i - first_len];
		i++;
	}
	str_joined[i] = '\0';
	return (str_joined);
}
