/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 12:18:20 by mac               #+#    #+#             */
/*   Updated: 2020/05/18 12:19:01 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*src_mem;
	unsigned char	*dst_mem;
	size_t			index;

	src_mem = (unsigned char*)src;
	dst_mem = (unsigned char*)dst;
	index = 0;
	while (n--)
	{
		dst_mem[index] = src_mem[index];
		index++;
	}
	return (dst_mem);
}
