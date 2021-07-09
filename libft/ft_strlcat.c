/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 15:34:30 by mac               #+#    #+#             */
/*   Updated: 2020/05/22 22:18:55 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t result_str_len;
	size_t number_of_characters_to_copy_from_src;
	size_t src_len;
	size_t dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dst_len < dstsize)
	{
		result_str_len = dst_len + src_len;
		dst += dst_len;
		number_of_characters_to_copy_from_src = dstsize - dst_len;
		ft_strlcpy(dst, src, number_of_characters_to_copy_from_src);
	}
	else
		result_str_len = dstsize + src_len;
	return (result_str_len);
}
