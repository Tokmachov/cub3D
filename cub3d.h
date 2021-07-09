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

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <math.h>

typedef	struct	s_texture_data
{
	void		*img_ptr;
	int			width;
	int			height;
	int			size_line;
	int			bpp;
	int			endian;
	char		*addr;
	float		x_image_to_texture_ratio;
	char		*location_dir;
}				t_texture_data;

typedef	struct	s_image
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

typedef	struct	s_sprite
{
	float			x;
	float			y;
	int				screen_size;
	int				screen_x_origin;
	int				screen_y_origin;
	float			distance;
	t_texture_data	img;
}				t_sprite;

typedef	struct	s_position
{
	float			x;
	float			y;
}				t_position;

typedef	struct	s_player
{
	float		x;
	float		y;
	float		heading;
}				t_player;

typedef	struct	s_game_params
{
	void			*mlx;
	void			*window;
	int				window_width;
	int				window_height;
	int				floor_color;
	int				ceiling_color;
	t_texture_data	textures[4];
	char			*sprite_texture_dir;
	t_sprite		*sprites;
	int				sprites_count;
	char			**map;
	int				rows_count;
	int				columns_count;
	t_position		window_center;
	float			distance_to_screen;
	t_image			buf_img;
	t_player		player;
	float			*hit_distances;
}				t_game_params;

typedef	enum	e_hit_side
{
	E = 0,
	N = 1,
	W = 2,
	S = 3,
	Error = 4
}				t_hit_side;

typedef	struct	s_size
{
	int			width;
	int			height;
}				t_size;

typedef	struct	s_wall_hit
{
	t_position	position;
	float		distance;
	t_hit_side	hit_side;
}				t_wall_hit;

typedef	struct	s_wall_slice
{
	float		origin_x;
	float		origin_y;
	float		corrected_height;
	float		original_height;
	float		offset;
	t_hit_side	hit_side;
	float		hit_distance;
}				t_wall_slice;

typedef	enum	e_direction
{
	RIGHT = 0,
	LEFT = 2,
	FORWARD = 1,
	BACK = 3
}				t_direction;

void			draw_sprite(t_sprite *sprite, t_game_params *params);

void			compute_sprite(t_sprite *sprite, t_game_params *params);
void			compute_sprite_size(t_sprite *sprite, t_game_params *params);
void			compute_sprite_screen_x_origin(t_sprite *sprite,
									t_game_params *params);
void			compute_sprite_screen_y_origin(t_sprite *sprite,
									t_game_params *params);
float			compute_sprite_dir(t_sprite *sprite, t_game_params *params);
float			compute_delta_angle(float heading, float sprite_dir);
void			compute_sprite_distance(t_sprite *sprite,
							t_game_params *params);
float			correct_sprite_distance(t_sprite *sprite,
								t_game_params *params);

# define PLAYER_PACE 8
# define PLAYER_TURN_INCREMENT 0.05
# define PLAYER_FOV (2 * M_PI) / 7
# define NORTH_HEADING (M_PI / 2.0)
# define SOUTH_HEADING 3 * (M_PI / 2)
# define WEST_HEADING M_PI
# define EAST_HEADING 0

# define SPRITE_HEIGHT 10
# define WINDOW_WIDTH_MIN 4
# define WINDOW_HEIGHT_MIN 4

# define CUBE_SIDE 32.0

# define INTERNAL_SPACE '0'
# define WALL '1'
# define SPRITE '2'
# define OUTER_SPACE ' '
# define NORTH_PLAYER 'N'
# define SOUTH_PLAYER 'S'
# define WEST_PLAYER 'W'
# define EAST_PLAYER 'E'
# define ALL_MAP_ELEMENTS "012 NSWE"
# define INTERNAL_MAP_ELEMENTS "02NSWE"
# define SURROUNDING_MAP_ELEMENTS "012NSWE"
# define PLAYER_POSITION_MAP_ELEMENTS "NSWE"

# define NOT_SET -1

# define NO_ERROR 0
# define MALLOC_ER 1
# define MALLOC_TXT "Error\nFailed to allocate memory"

# define RES_FMT_ERR 2
# define RES_FMT_TXT "Error\nWrong format of resolution"

# define UNKNOWN_CFG_ID_ER 4
# define UNKNOWN_CFG_TXT "Error\nUnknown config identifier or map is not last."

# define PARAMS_MISSED_ER 6
# define PARAMS_MISSED_TXT "Error\nSome game parameters are missed."

# define MAP_PARSE_ER 7
# define MAP_PARSE_TXT "Error\nMap parsing error."

# define FLOOR_CLR_FMT_ER 8
# define FLOOR_CLR_FMT_TXT "Error\nWrong floor color format."

# define CEIL_CLR_FMT_ER 9
# define CEIL_CLR_FMT_TXT "Error\nWrong ceiling color format."

# define TEXTURE_ER 10
# define TEXTURE_ER_TXT "Error\nTexture parsing error."

# define WRN_TXTR_LOC_ER 11
# define WRN_TXTR_LOC_ER_TXT "Error\nWrong texture path."

# define DUPL_CFG_ER 12
# define DUPL_CFG_ER_TXT "Error\nConfig parameter is duplicated."

# define SPRT_IMG_NULL_ER 13
# define SPRT_IMG_NULL_TXT "Error\nSprite image data is missed."

# define FAIL_PARS_MAP_ER 14
# define FAIL_PARS_MAP_TXT "Error\nMap is invalid."

# define INVLD_MAP_ER 15
# define INVLD_MAP_TXT "Error\nMap is invalid."

# define MNY_PLRS_ER 16
# define MNY_PLRS_TXT "Error\nThere are more then one players on map."

# define NO_PLR_ER 17
# define NO_PLR_TXT "Error\nThere is no player on map."

# define WRONG_ARG_NUM 18
# define WRONG_ARG_NUM_TXT "Error\nWrong number of arguments to program."

# define WRN_FILE_EXT 19
# define WRN_FILE_EXT_TXT "Error\nWrong scene file extension."

# define FAIL_OPN_FILE_ER 20
# define FAIL_OPN_FILE_TXT "Error\nFail to open scene file."

# define GNL_ER 21
# define GNL_TXT "Error\nError when reading line from scene file."

# define RGB_PARS_ER 22
# define RGB_PARS_TXT "Error\nFailed to parse rgb colors."

# define WRN_SAVE_FLG_ER 23
# define WRN_SAVE_FLG_TXT "Error\nWrong save flag."

# define RSN_INVLD_VAL_ER 24
# define RSN_INVLD_VAL_TXT "Error\nInvalid resolution value."

# define MLX_INIT_FAIL_ER 25
# define MLX_INIT_FAIL_TXT "Error\nFailed to initialize mlx."

# define BF_IMG_INIT_FAIL_ER 26
# define BF_IMG_INIT_FAIL_TXT "Error\nFailed to alloc buff img."

typedef struct	s_bitmap_file_header
{
	char			bitmap_type[2];
	int				file_size;
	short			reserved1;
	short			reserved2;
	unsigned int	offset_bits;
}				t_bitmap_file_header;

typedef struct	s_bitmap_image_header
{
	unsigned int	size_header;
	unsigned int	width;
	unsigned int	height;
	short int		planes;
	short int		bit_count;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	clr_used;
	unsigned int	clr_important;
}				t_bitmap_image_header;

int				make_screen(t_game_params *params);

int				validate_save_flag(char *save_flag);
int				render_next_frame(void *params);

void			set_game_params_to_unset_values(t_game_params *params);
void			set_hooks_mlx(t_game_params *params);
void			make_bmp_screen_shot(t_game_params *params);
void			exit_cleanly_if_error(int result_code, t_game_params *params);
int				validate_scene_file_extension(char *file_path);
int				init_game_params(char *scene_file_path, t_game_params *params);
int				open_window(t_game_params *params);

void			draw_walls_ceiling_and_floor(t_game_params *params);
void			draw_textured_wall_slice(t_game_params *params,
								t_wall_slice *wall_slice, int slice_number);
void			draw_ceiling_slice(t_game_params *params,
						t_wall_slice wall_slice, int slice_x);
void			draw_floor_slice(t_game_params *params,
						t_wall_slice wall_slice, int slice_x);
int				create_rgb(int t, int r, int g, int b);

void			draw_sprites(t_game_params *params);
void			draw_sprite(t_sprite *sprite, t_game_params *params);
void			draw_sprite_slice(int screen_x, int sprite_x,
						t_sprite *sprite, t_game_params *params);
int				get_sprite_pixel_color(int sprite_x,
							int sprite_y, t_sprite *sprite);
void			my_mlx_pixel_put(t_image *img, int x, int y, int color);

float			compute_ray_angle(t_game_params *params,
						int current_ray_number);

void			compute_wall_slice(t_wall_slice *wall_slice,
						int ray_num, t_game_params *params);
void			compute_wall_hit(float ray_angle,
						t_wall_hit *wall_hit, t_game_params *params);
void			compute_h_hit_pos(t_position *hit_position,
						float angle, t_game_params *params);
void			compute_v_hit_pos(t_position *hit_position,
						float angle, t_game_params *params);
void			compute_hit_pos(t_position *first_hit, float x_increment,
						float y_increment, t_game_params *params);
float			compute_x_increment(float y_increment, float angle);
float			compute_y_increment(float x_increment, float angle);
t_bool			is_facing_right(float angle);
t_bool			is_facing_up(float angle);

int				get_text_pxl_color(t_texture_data *texture_data,
						int x, int y);
float			compute_texture_x(t_wall_slice *slice,
						t_game_params *params);
float			compute_texture_y(float slice_dy, t_wall_slice *slice,
						t_game_params *params);

int				parse_scene(char *scene_file_path, t_game_params *params);
int				parse_resolution(char *str, t_game_params *params);
int				parse_floor_color(char *str, t_game_params *params);
int				parse_ceiling_color(char *str, t_game_params *params);
int				parse_config(int fd, t_game_params *params);
int				parse_rgb(char *str, int *color);
char			*parse_texture_dir(char *str);
int				parse_no_texture_dir(char *str, t_game_params *params);
int				parse_so_texture_dir(char *str, t_game_params *params);
int				parse_we_texture_dir(char *str, t_game_params *params);
int				parse_ea_texture_dir(char *str, t_game_params *params);
int				parse_sprite_texture_dir(char *str, t_game_params *params);
int				parse_player(t_game_params *params);
int				parse_sprites(t_game_params *params);
int				set_textures_images(t_game_params *params);
int				set_sprites_images(t_game_params *params);
int				parse_map(int fd, t_game_params *params);
char			**get_map(int fd);
t_bool			has_all_neighbours(int row, int col, t_game_params *params);
t_bool			is_map_valid(t_game_params *params);
int				validate_players_count_on_map(t_game_params *params);
t_bool			is_player(char c);
void			set_sprites_img_values_null(t_game_params *params);
void			correct_resolution(t_game_params *params,
						int curr_width, int curr_height);
int				parse_int_limited(char *str, int upper_limit);

typedef int	(*t_parse_func)(char *, t_game_params *params);

typedef	struct	s_id_and_func
{
	char			*id;
	t_parse_func	f;
}				t_id_and_func;

t_bool			is_error(int error_code);
int				count_words(char **str);
char			*skip_to_next_coma_separated_number_parameter(char *str);
char			*skip_digits(char *str);
void			print_arr_of_str(char **str);
void			print_lst(t_list *head);
void			substitute_chars(char ch, char replacer, char **map);
int				get_columns_count(char **arr);
int				get_rows_count(char **arr);
size_t			find_longest_line_len(char **map);

void			put_error_message(int er_cod);

void			free_game_params(t_game_params *params);
char			*skip_spaces(char *str);
int				words_count(char **str);
void			free_str_array(char **arr);
void			reduce_to_one_circle(float *angle);
void			increment_angle(float *angle, float increment);
void			assert(t_bool condition, char *message);

int				handle_key(int key, void *params);
int				close_through_red_cross(void *params);
void			exit_cleanly(t_game_params *params);

# define W_KEY 13
# define A_KEY 0
# define D_KEY 2
# define S_KEY 1
# define LEFT_ARROW_KEY 123
# define RIGHT_ARROW_KEY 124
# define ESC_KEY 53

void			move_player(t_direction dir, t_player *player);
void			change_heading(t_direction side, t_player *player);

#endif
