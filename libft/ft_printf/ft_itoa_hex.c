/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 11:40:55 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 17:00:04 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	calc_hexlen(unsigned int num)
{
	int	hexlen;

	hexlen = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num = num / 16;
		hexlen++;
	}
	return (hexlen);
}

STRING		ft_itoa_hex(unsigned int num, t_bool is_uppercase)
{
	int		hexlen;
	STRING	hexstr;
	char	first_substitute;

	first_substitute = is_uppercase ? 'A' : 'a';
	hexlen = calc_hexlen(num);
	hexstr = (STRING)ft_calloc(hexlen + 1, sizeof(char));
	if (!hexstr)
		return (NULL);
	while (hexlen--)
	{
		if (num % 16 <= 9)
			hexstr[hexlen] = '0' + num % 16;
		else
			hexstr[hexlen] = first_substitute + (num % 16 - 10);
		num /= 16;
	}
	return (hexstr);
}
