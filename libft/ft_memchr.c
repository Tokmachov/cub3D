/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 15:21:31 by mac               #+#    #+#             */
/*   Updated: 2020/05/17 15:22:43 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *input;
	unsigned char searched_ch;

	input = (unsigned char*)s;
	searched_ch = (unsigned char)c;
	while (n--)
	{
		if (*input == searched_ch)
			return (input);
		input++;
	}
	return (0);
}
