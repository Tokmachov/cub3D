/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 15:39:37 by mac               #+#    #+#             */
/*   Updated: 2020/05/17 15:40:56 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char *result_ptr;
	char searched_c;
	char *temp_s;

	result_ptr = 0;
	searched_c = (char)c;
	temp_s = (char*)s;
	while (*temp_s)
	{
		if (*temp_s == searched_c)
			result_ptr = temp_s;
		temp_s++;
	}
	if (searched_c == '\0')
		return (temp_s);
	else
		return (result_ptr);
}
