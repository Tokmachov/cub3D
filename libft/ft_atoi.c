/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 16:03:00 by mac               #+#    #+#             */
/*   Updated: 2020/05/18 13:54:48 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str && (*str == ' ' || *str == '\f' ||
*str == '\n' || *str == '\r' || *str == '\t' || *str == '\v'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			sign = -1;
		}
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}
