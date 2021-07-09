/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_filled_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 15:57:58 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 16:20:24 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

STRING	make_filled_str(int len, char fillingchr)
{
	STRING	str;

	str = (STRING)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	str = (STRING)ft_memset(str, fillingchr, len);
	return (str);
}
