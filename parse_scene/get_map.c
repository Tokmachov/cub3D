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

static	char	**convert_lst_to_arr(t_list *head)
{
	int		list_len;
	char	**arr;
	int		i;

	list_len = ft_lstsize(head);
	arr = (char**)malloc((list_len + 1) * sizeof(char*));
	if (!arr)
		return (NULL);
	i = 0;
	while (head)
	{
		arr[i] = head->content;
		i++;
		head = head->next;
	}
	arr[i] = NULL;
	return (arr);
}

static	void	free_list_and_line(t_list **lst, char *line)
{
	free(line);
	ft_lstclear(lst, free);
}

static	t_list	*get_map_lines_lst(int fd)
{
	int		gnl_res;
	char	*line;
	t_list	*new_list;
	t_list	*head;

	head = NULL;
	line = NULL;
	while ((gnl_res = get_next_line(fd, &line)) > 0)
	{
		if (!(new_list = ft_lstnew(line)))
		{
			free_list_and_line(&head, line);
			return (NULL);
		}
		ft_lstadd_back(&head, new_list);
	}
	if (gnl_res < 0 || !(new_list = ft_lstnew(line)))
	{
		free_list_and_line(&head, line);
		return (NULL);
	}
	ft_lstadd_back(&head, new_list);
	return (head);
}

char			**get_map(int fd)
{
	t_list	*map_lines_lst_head;
	char	**map;

	map_lines_lst_head = get_map_lines_lst(fd);
	if (!map_lines_lst_head)
		return (NULL);
	map = convert_lst_to_arr(map_lines_lst_head);
	if (!map)
	{
		ft_lstclear(&map_lines_lst_head, free);
		return (NULL);
	}
	ft_lstclear(&map_lines_lst_head, NULL);
	return (map);
}
