/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:19:18 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 17:10:46 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	count_digits(unsigned int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

STRING		ft_itoa_u(unsigned int n)
{
	int		digitis_count;
	STRING	result;

	digitis_count = count_digits(n);
	result = (STRING)ft_calloc(digitis_count + 1, sizeof(char));
	if (!result)
		return (NULL);
	while (digitis_count-- > 0)
	{
		result[digitis_count] = '0' + n % 10;
		n = n / 10;
	}
	return (result);
}
