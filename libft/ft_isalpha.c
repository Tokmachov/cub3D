/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 16:11:18 by mac               #+#    #+#             */
/*   Updated: 2020/05/17 16:51:07 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (TRUE);
	else
		return (FALSE);
}

static	int	ft_islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (TRUE);
	else
		return (FALSE);
}

int			ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}
