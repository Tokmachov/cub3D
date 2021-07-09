/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 15:34:24 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 17:03:00 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	get_sign(long long int n)
{
	if (n < 0)
		return ('-');
	else
		return ('+');
}

static	size_t	calc_numlen(long long int n)
{
	size_t l;

	l = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		l++;
	while (n != 0)
	{
		n = n / 10;
		l++;
	}
	return (l);
}

STRING			ft_itoa_ll(long long int n)
{
	char	sign;
	size_t	numlen;
	STRING	string_num;

	sign = get_sign(n);
	numlen = calc_numlen(n);
	string_num = (STRING)ft_calloc(numlen + 1, sizeof(char));
	if (!string_num)
		return (NULL);
	while (numlen--)
	{
		string_num[numlen] = '0' + ft_abs(n % 10);
		n /= 10;
	}
	if (sign == '-')
		string_num[0] = '-';
	return (string_num);
}
