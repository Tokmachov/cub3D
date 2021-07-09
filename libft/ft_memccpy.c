/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 12:20:37 by mac               #+#    #+#             */
/*   Updated: 2020/05/18 12:21:43 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *dst_mem;
	unsigned char *src_mem;
	unsigned char ch;

	dst_mem = (unsigned char*)dst;
	src_mem = (unsigned char*)src;
	ch = (unsigned char)c;
	while (n--)
	{
		*dst_mem = *src_mem;
		dst_mem++;
		src_mem++;
		if (*(dst_mem - 1) == ch)
			return (dst_mem);
	}
	return (0);
}
