/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 11:05:37 by mac               #+#    #+#             */
/*   Updated: 2020/05/18 11:07:27 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		result_str_len;
	char	*result_str;
	int		index;

	result_str_len = ft_strlen(s);
	result_str = (char*)malloc((result_str_len + 1) * sizeof(char));
	if (result_str)
	{
		index = 0;
		while (s[index])
		{
			result_str[index] = f(index, s[index]);
			index++;
		}
		result_str[index] = '\0';
		return (result_str);
	}
	else
		return (0);
}
