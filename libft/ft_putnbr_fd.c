/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 11:11:12 by mac               #+#    #+#             */
/*   Updated: 2020/05/20 20:41:13 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_putsign(int sign, int fd)
{
	if (sign < 0)
		ft_putchar_fd('-', fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	int sign;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	if ((n >= 0 && n <= 9) || (n <= 0 && n >= -9))
	{
		ft_putsign(sign, fd);
		ft_putchar_fd('0' + n * sign, fd);
	}
	else
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putchar_fd('0' + (n % 10) * sign, fd);
	}
}
