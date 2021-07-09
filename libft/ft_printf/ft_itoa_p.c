/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 10:03:49 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 17:06:39 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		calc_addr_len(uintmax_t p)
{
	int	len;

	if (p == 0)
		return (1);
	len = 0;
	while (p > 0)
	{
		p = p / 16;
		len++;
	}
	return (len);
}

STRING	ft_itoa_p(uintmax_t p)
{
	int		addr_len;
	STRING	result;

	addr_len = calc_addr_len(p);
	result = (STRING)ft_calloc(addr_len + 1, sizeof(char));
	if (!result)
		return (NULL);
	while (addr_len--)
	{
		if (p % 16 > 9)
			result[addr_len] = 'a' + p % 16 - 10;
		else
			result[addr_len] = '0' + p % 16;
		p = p / 16;
	}
	return (result);
}
