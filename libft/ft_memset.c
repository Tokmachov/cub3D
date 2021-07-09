/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 12:09:29 by mac               #+#    #+#             */
/*   Updated: 2020/05/17 13:30:24 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*memory;
	unsigned char	ch;
	size_t			index;

	memory = (unsigned char*)b;
	ch = (unsigned char)c;
	index = 0;
	while (index < len)
	{
		memory[index] = ch;
		index += 1;
	}
	return (b);
}
