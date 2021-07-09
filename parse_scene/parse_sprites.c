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

static	void	parse_sprite_pos(
		int row,
		int col,
		int sprite_num,
		t_game_params *params)
{
	params->sprites[sprite_num].x = col * CUBE_SIDE + CUBE_SIDE / 2;
	params->sprites[sprite_num].y = row * CUBE_SIDE + CUBE_SIDE / 2;
}

static	int		count_sprites(char **map)
{
	int row;
	int column;
	int count;

	row = 0;
	count = 0;
	while (map[row])
	{
		column = 0;
		while (map[row][column])
		{
			if (map[row][column] == SPRITE)
				count++;
			column++;
		}
		row++;
	}
	return (count);
}

int				parse_sprites(t_game_params *params)
{
	int row;
	int col;
	int sprite_num;

	params->sprites_count = count_sprites(params->map);
	params->sprites = malloc(params->sprites_count * sizeof(t_sprite));
	if (!params->sprites)
		return (MALLOC_ER);
	sprite_num = 0;
	row = 0;
	while (params->map[row])
	{
		col = 0;
		while (params->map[row][col])
		{
			if (params->map[row][col] == SPRITE)
			{
				parse_sprite_pos(row, col, sprite_num, params);
				sprite_num++;
			}
			col++;
		}
		row++;
	}
	return (NO_ERROR);
}
