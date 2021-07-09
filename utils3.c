/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolynn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:55:23 by sjolynn           #+#    #+#             */
/*   Updated: 2020/08/25 16:41:18 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

size_t	find_longest_line_len(char **map)
{
	int i;
	int longest_len;
	int current_line_len;

	i = 0;
	longest_len = 0;
	while (map[i])
	{
		current_line_len = ft_strlen(map[i]);
		if (current_line_len > longest_len)
			longest_len = current_line_len;
		i++;
	}
	return (longest_len);
}
