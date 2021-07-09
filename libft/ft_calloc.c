/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 17:27:58 by mac               #+#    #+#             */
/*   Updated: 2020/05/17 17:28:56 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	mem_len;
	void	*ptr;

	mem_len = count * size;
	ptr = malloc(mem_len);
	if (ptr != 0)
	{
		ft_bzero(ptr, mem_len);
		return (ptr);
	}
	else
		return (ptr);
}
