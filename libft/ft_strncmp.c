/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 16:01:03 by mac               #+#    #+#             */
/*   Updated: 2020/05/17 16:02:13 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;
	int				result;

	result = 0;
	while (n--)
	{
		c1 = (unsigned char)*s1;
		c2 = (unsigned char)*s2;
		result = c1 - c2;
		if (result != 0 || (c1 == '\0' && c2 == '\0'))
			return (result);
		s1++;
		s2++;
	}
	return (0);
}
