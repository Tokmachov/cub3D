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

#include "cub3d.h"

void	put_error_message(int er_cod)
{
	(er_cod == MALLOC_ER) ? ft_putendl_fd(MALLOC_TXT, 2) : 0;
	(er_cod == RES_FMT_ERR) ? ft_putendl_fd(RES_FMT_TXT, 2) : 0;
	(er_cod == UNKNOWN_CFG_ID_ER) ? ft_putendl_fd(UNKNOWN_CFG_TXT, 2) : 0;
	(er_cod == PARAMS_MISSED_ER) ? ft_putendl_fd(PARAMS_MISSED_TXT, 2) : 0;
	(er_cod == MAP_PARSE_ER) ? ft_putendl_fd(MAP_PARSE_TXT, 2) : 0;
	(er_cod == FLOOR_CLR_FMT_ER) ? ft_putendl_fd(FLOOR_CLR_FMT_TXT, 2) : 0;
	(er_cod == CEIL_CLR_FMT_ER) ? ft_putendl_fd(CEIL_CLR_FMT_TXT, 2) : 0;
	(er_cod == TEXTURE_ER) ? ft_putendl_fd(TEXTURE_ER_TXT, 2) : 0;
	(er_cod == WRN_TXTR_LOC_ER) ? ft_putendl_fd(WRN_TXTR_LOC_ER_TXT, 2) : 0;
	(er_cod == DUPL_CFG_ER) ? ft_putendl_fd(DUPL_CFG_ER_TXT, 2) : 0;
	(er_cod == SPRT_IMG_NULL_ER) ? ft_putendl_fd(SPRT_IMG_NULL_TXT, 2) : 0;
	(er_cod == FAIL_PARS_MAP_ER) ? ft_putendl_fd(FAIL_PARS_MAP_TXT, 2) : 0;
	(er_cod == INVLD_MAP_ER) ? ft_putendl_fd(INVLD_MAP_TXT, 2) : 0;
	(er_cod == MNY_PLRS_ER) ? ft_putendl_fd(MNY_PLRS_TXT, 2) : 0;
	(er_cod == NO_PLR_ER) ? ft_putendl_fd(NO_PLR_TXT, 2) : 0;
	(er_cod == WRONG_ARG_NUM) ? ft_putendl_fd(WRONG_ARG_NUM_TXT, 2) : 0;
	(er_cod == WRN_FILE_EXT) ? ft_putendl_fd(WRN_FILE_EXT_TXT, 2) : 0;
	(er_cod == FAIL_OPN_FILE_ER) ? ft_putendl_fd(FAIL_OPN_FILE_TXT, 2) : 0;
	(er_cod == GNL_ER) ? ft_putendl_fd(GNL_TXT, 2) : 0;
	(er_cod == RGB_PARS_ER) ? ft_putendl_fd(RGB_PARS_TXT, 2) : 0;
	(er_cod == WRN_SAVE_FLG_ER) ? ft_putendl_fd(WRN_SAVE_FLG_TXT, 2) : 0;
	(er_cod == RSN_INVLD_VAL_ER) ? ft_putendl_fd(RSN_INVLD_VAL_TXT, 2) : 0;
	(er_cod == MLX_INIT_FAIL_ER) ? ft_putendl_fd(MLX_INIT_FAIL_TXT, 2) : 0;
}
