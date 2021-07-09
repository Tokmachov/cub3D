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

void	print_lst(t_list *head)
{
	while (head)
	{
		ft_printf("%s\n", head->content);
		head = head->next;
	}
}

void	print_arr_of_str(char **str)
{
	while (*str)
	{
		ft_printf("%s|\n", *str);
		str++;
	}
}

void	substitute_chars(char ch, char replacer, char **map)
{
	int	column;
	int	row;

	column = 0;
	row = 0;
	while (map[row])
	{
		column = 0;
		while (map[row][column])
		{
			if (map[row][column] == ch)
				map[row][column] = replacer;
			column++;
		}
		row++;
	}
}

int		get_rows_count(char **arr)
{
	int rows;

	rows = 0;
	while (*arr)
	{
		arr++;
		rows++;
	}
	return (rows);
}

int		get_columns_count(char **arr)
{
	int columns;

	columns = 0;
	while (arr[0][columns])
	{
		columns++;
	}
	return (columns);
}
