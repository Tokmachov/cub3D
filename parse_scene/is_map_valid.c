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

#include "../cub3d.h"
#include "../libft/libft.h"

static	t_bool	is_valid_map_element(char el)
{
	return (ft_strchr(ALL_MAP_ELEMENTS, el) != NULL);
}

static	t_bool	is_internal_map_element(char el)
{
	return (ft_strchr(INTERNAL_MAP_ELEMENTS, el) != NULL);
}

t_bool			is_map_valid(t_game_params *params)
{
	int		row;
	int		column;
	char	map_element;
	char	**map;

	row = 0;
	map = params->map;
	while (map[row])
	{
		column = 0;
		while ((map_element = map[row][column]))
		{
			if (!is_valid_map_element(map_element))
				return (false);
			if (is_internal_map_element(map_element)
			&& !has_all_neighbours(row, column, params))
				return (false);
			column++;
		}
		row++;
	}
	return (true);
}
