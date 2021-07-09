/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 10:57:54 by mac               #+#    #+#             */
/*   Updated: 2020/05/18 11:03:59 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		count_of_digits_in(int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count += 1;
	while (n)
	{
		n /= 10;
		count += 1;
	}
	return (count);
}

static	char	get_last_digit_from(int n)
{
	int last_digit;

	last_digit = n % 10;
	if (last_digit < 0)
		return (-last_digit + '0');
	else
		return (last_digit + '0');
}

static	void	cut_last_digit_in(int *n)
{
	*n = (*n) / 10;
}

char			*ft_itoa(int n)
{
	char	*num_representation;
	int		digits_count;
	int		sign;

	digits_count = count_of_digits_in(n);
	num_representation = (char*)malloc(sizeof(char) * (digits_count + 1));
	if (n < 0)
		sign = -1;
	else
		sign = 1;
	if (num_representation != 0)
	{
		ft_bzero(num_representation, (digits_count + 1));
		while (digits_count--)
		{
			num_representation[digits_count] = get_last_digit_from(n);
			cut_last_digit_in(&n);
		}
		if (sign < 0)
			num_representation[0] = '-';
		return (num_representation);
	}
	else
		return (0);
}
