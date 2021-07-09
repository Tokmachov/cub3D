# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjolynn <sjolynn@student.21-school.ru      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/03 17:16:27 by sjolynn           #+#    #+#              #
#    Updated: 2020/08/25 16:31:08 by sjolynn          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC_COMPUTE_SPRITE = $(addprefix compute_sprite/, compute_sprite.c \
	compute_sprite_screen_x_origin.c \
	compute_sprite_screen_y_origin.c compute_sprite_size.c \
	compute_sprite_dir.c \
	compute_delta_angle.c compute_sprite_distance.c correct_sprite_distance.c)

SRC_COMPUTE_WALL_SLICE = $(addprefix compute_wall_slice/,compute_h_hit_pos.c \
	compute_hit_pos.c \
	compute_v_hit_pos.c compute_wall_hit.c compute_wall_slice.c \
	compute_x_increment.c compute_y_increment.c)

SRC_DRAW = $(addprefix draw/,create_rgb.c draw_ceiling_slice.c \
	draw_floor_slice.c \
	draw_textured_wall_slice.c draw_walls_ceiling_and_floor.c \
	my_mlx_pixel_put.c)

SRC_DRAW_SPRITES = $(addprefix draw_sprites/,draw_sprite.c \
	draw_sprite_slice.c draw_sprites.c \
	get_sprite_pixel_color.c)

SRC_INIT_GAME_PARAMS = $(addprefix init_game_params/, init_game_params.c \
	set_buffer_image.c \
	set_distance_to_projection_screen.c set_hit_distances_arr.c \
	set_mlx_window_center.c set_sprites_images.c \
	set_textures_images.c set_sprites_img_values_null.c init_mlx.c)

PARSE_SCENE = $(addprefix parse_scene/,get_map.c has_all_neighbours.c \
	is_map_valid.c \
	is_player.c parse_ceiling_color.c parse_config.c parse_floor_color.c \
	parse_map.c parse_player.c parse_resolution.c parse_rgb.c parse_scene.c \
	parse_sprites.c parse_texture_dir.c parse_textures.c \
	validate_players_count_on_map.c correct_resolution.c parse_int_limited.c)

SRC_MAIN_DIR = close_through_red_cross.c compute_ray_angle.c \
	compute_texture_pixel_coordinates.c cub3d.c \
	exit_cleanly_if_error.c free_game_params.c handle_key.c is_facing_right.c \
	is_facing_up.c player_movements.c put_error_message.c \
	render_next_frame.c save_screen.c set_game_params_to_unset_values.c \
	utils.c utils1.c utils2.c utils3.c validate_save_flag.c \
	validate_scene_file_extension.c set_hooks_mlx.c make_bmp_screen_shot.c \
	exit_cleanly.c open_window.c

SRCS =  $(SRC_MAIN_DIR) $(SRC_INIT_GAME_PARAMS) $(SRC_DRAW) \
	$(SRC_COMPUTE_WALL_SLICE) $(SRC_COMPUTE_SPRITE) $(SRC_DRAW_SPRITES) \
	$(PARSE_SCENE)

HEADERS = cub3d.h init_game_params/init_game_params.h

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c -g

LIBFT_ARC = libft/libft.a
MLX_ARC = mlx/libmlx.dylib

.PHONY: all clean fclean re

all: $(NAME)
 
$(NAME): $(OBJS) $(LIBFT_ARC) $(MLX_ARC)
	cp mlx/libmlx.dylib .
	$(CC) -L. -lmlx -framework OpenGL -framework AppKit -Llibft -lft $(OBJS) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -Imlx -Ilibft -I. $< -o $@

$(LIBFT_ARC): libft/*.c libft/ft_printf/*.c libft/libft.h libft/ft_printf/ft_printf.h
	make -C libft

$(MLX_ARC):
	make -C mlx

clean:
	make clean -C libft
	make clean -C mlx
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	make fclean -C mlx
	rm -f libmlx.dylib
	rm -f $(NAME)
re: fclean all
