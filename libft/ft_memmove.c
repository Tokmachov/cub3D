/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 15:19:21 by mac               #+#    #+#             */
/*   Updated: 2020/05/22 13:12:02 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	memcpy_backwards(void *dst, void *src, size_t len)
{
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	dst_tmp = (unsigned char*)dst;
	src_tmp = (unsigned char*)src;
	dst_tmp += len - 1;
	src_tmp += len - 1;
	while (len--)
	{
		*dst_tmp = *src_tmp;
		dst_tmp--;
		src_tmp--;
	}
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	dst_tmp = (unsigned char*)dst;
	src_tmp = (unsigned char*)src;
	if (dst_tmp > src_tmp)
	{
		memcpy_backwards(dst_tmp, src_tmp, len);
	}
	else if (dst_tmp < src_tmp)
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
