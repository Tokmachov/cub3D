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

int				validate_players_count_on_map(t_game_params *params)
{
	int row;
	int column;
	int players_count;

	players_count = 0;
	row = 0;
	while (row < params->rows_count)
	{
		column = 0;
		while (column < params->columns_count)
		{
			if (is_player(params->map[row][column]))
				players_count++;
			column++;
		}
		row++;
	}
	if (players_count == 0)
		return (NO_PLR_ER);
	else if (players_count > 1)
		return (MNY_PLRS_ER);
	else
		return (NO_ERROR);
}
