/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 15:23:53 by mac               #+#    #+#             */
/*   Updated: 2020/05/17 15:29:16 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*mem1;
	unsigned char	*mem2;
	int				result;

	mem1 = (unsigned char*)s1;
	mem2 = (unsigned char*)s2;
	result = 0;
	while (n--)
	{
		result = *mem1 - *mem2;
		if (result != 0)
			return (result);
		mem1++;
		mem2++;
	}
	return (result);
}
