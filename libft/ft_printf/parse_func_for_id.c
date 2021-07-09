/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_func_for_id.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 11:54:38 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 18:35:12 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

static	t_parse_func	*make_sccapx_capl_l_funcs(void)
{
	t_parse_func *funcs;

	funcs = (t_parse_func*)malloc(5 * sizeof(t_parse_func));
	if (!funcs)
		return (NULL);
	funcs[0] = &parse_s_arg;
	funcs[1] = &parse_c_arg;
	funcs[2] = &parse_capital_x_arg;
	funcs[3] = &parse_ll_arg;
	funcs[4] = &parse_ll_arg;
	return (funcs);
}

static	t_parse_func	*make_dipux_funcs(void)
{
	t_parse_func *funcs;

	funcs = (t_parse_func*)malloc(5 * sizeof(t_parse_func));
	if (!funcs)
		return (NULL);
	funcs[0] = &parse_int_arg;
	funcs[1] = &parse_int_arg;
	funcs[2] = &parse_p_arg;
	funcs[3] = &parse_u_arg;
	funcs[4] = &parse_x_arg;
	return (funcs);
}

static	t_parse_func	func_for_id_sccapx_capl_l(char id)
{
	t_parse_func	result_func;
	t_parse_func	*funcs;
	char			*ids;
	int				i;

	result_func = NULL;
	funcs = make_sccapx_capl_l_funcs();
	if (!funcs)
		return (NULL);
	ids = "scXLl";
	i = 0;
	while (ids[i])
	{
		if (ids[i] == id)
		{
			result_func = funcs[i];
			break ;
		}
		i++;
	}
	free(funcs);
	return (result_func);
}

static	t_parse_func	func_for_id_dipux(char id)
{
	t_parse_func	result_func;
	t_parse_func	*funcs;
	char			*ids;
	int				i;

	result_func = NULL;
	funcs = make_dipux_funcs();
	if (!funcs)
		return (NULL);
	ids = "dipux";
	i = 0;
	while (ids[i])
	{
		if (ids[i] == id)
		{
			result_func = funcs[i];
			break ;
		}
		i++;
	}
	free(funcs);
	return (result_func);
}

t_parse_func			parse_func_for_id(char id)
{
	t_parse_func func;

	if ((func = func_for_id_dipux(id)) != NULL)
		return (func);
	else if ((func = func_for_id_sccapx_capl_l(id)) != NULL)
		return (func);
	else
		return (NULL);
}
