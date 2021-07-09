/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 15:37:30 by mac               #+#    #+#             */
/*   Updated: 2020/05/18 16:18:41 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	searched_ch;
	char	*ptr;

	searched_ch = (char)c;
	ptr = (char*)s;
	while (*ptr)
	{
		if (*ptr == searched_ch)
			return (ptr);
		ptr++;
	}
	if (searched_ch == '\0')
		return (ptr);
	else
		return (0);
}
