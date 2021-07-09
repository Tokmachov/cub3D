/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolynn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:57:48 by sjolynn           #+#    #+#             */
/*   Updated: 2020/08/25 15:57:54 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"

static	t_bool	has_up_neighbour(int row, int col, t_game_params *params)
{
	int		neighbour_row;
	int		neighbour_column;
	char	neighbour_element;

	neighbour_row = row - 1;
	if (neighbour_row < 0)
		return (false);
	neighbour_column = col;
	neighbour_element = params->map[neighbour_row][neighbour_column];
	if (!ft_strchr(SURROUNDING_MAP_ELEMENTS, neighbour_element))
		return (false);
	return (true);
}

static	t_bool	has_down_neighbour(int row, int col, t_game_params *params)
{
	int		neighbour_row;
	int		neighbour_column;
	char	neighbour_element;

	neighbour_row = row + 1;
	if (neighbour_row >= params->rows_count)
		return (false);
	neighbour_column = col;
	neighbour_element = params->map[neighbour_row][neighbour_column];
	if (!ft_strchr(SURROUNDING_MAP_ELEMENTS, neighbour_element))
		return (false);
	return (true);
}

static	t_bool	has_left_neighbour(int row, int col, t_game_params *params)
{
	int		neighbour_row;
	int		neighbour_column;
	char	neighbour_element;

	neighbour_row = row;
	neighbour_column = col - 1;
	if (neighbour_column < 0)
		return (false);
	neighbour_element = params->map[neighbour_row][neighbour_column];
	if (!ft_strchr(SURROUNDING_MAP_ELEMENTS, neighbour_element))
		return (false);
	return (true);
}

static	t_bool	has_right_neighbour(int row, int col, t_game_params *params)
{
	int		neighbour_row;
	int		neighbour_column;
	char	neighbour_element;

	neighbour_row = row;
	neighbour_column = col + 1;
	if (neighbour_column >= params->columns_count)
		return (false);
	neighbour_element = params->map[neighbour_row][neighbour_column];
	if (!ft_strchr(SURROUNDING_MAP_ELEMENTS, neighbour_element))
		return (false);
	return (true);
}

t_bool			has_all_neighbours(int row, int col, t_game_params *params)
{
	if (!has_up_neighbour(row, col, params))
		return (false);
	if (!has_down_neighbour(row, col, params))
		return (false);
	if (!has_left_neighbour(row, col, params))
		return (false);
	if (!has_right_neighbour(row, col, params))
		return (false);
	return (true);
}
