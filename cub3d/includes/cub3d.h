/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:46:34 by mclown            #+#    #+#             */
/*   Updated: 2021/03/15 19:48:13 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <math.h>

# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2

# define KEY_LEFT				123
# define KEY_RIGHT				124

# define KEY_ESC				53

# define NORTH					0
# define SOUTH					1
# define WEST					2
# define EAST					3
# define SPRITE					4

# define VALID_MAP_CHARACTERS	"NSWE012"
# define PLAYER_CHARACTERS		"NSWE"

typedef struct	s_img {
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			height;
	int			width;
}				t_img;

typedef struct	s_mlx {
	void		*ptr;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_mlx;

typedef struct	s_point {
	int			x;
	int			y;
}				t_point;

typedef struct	s_vector {
	double		x;
	double		y;
}				t_vector;

typedef struct	s_color {
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_pl {
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
}				t_pl;

typedef struct	s_algo_data {
	double		camera_x;
	t_vector	ray_dir;
	t_vector	side_dist;
	t_vector	delta_dist;
	t_point		step;
	t_point		map;
	double		pwd;
	int			hit;
	int			side;
	int			line_h;
	int			draw_start;
	int			draw_end;
	double		old_dir_x;
	double		old_plane_x;
}				t_algo_data;

typedef struct	s_txtr_data {
	t_img		*t_arr;
	int			text_num;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		step;
	double		text_pos;
	size_t		color;
}				t_txtr_data;

typedef struct	s_map_data {

	int			scr_w;
	int			scr_h;
	char		**text_path;
	t_color		fl_color;
	t_color		ceil_color;
	char		**map;
	int			map_h;
	int			map_max_w;
	int			fd;
	t_list		*head;
	int			isplayer;
}				t_map_data;

typedef struct	s_key {
	int			w;
	int			s;
	int			a;
	int			d;
	int			left;
	int			right;
}				t_key;

typedef struct	s_sprite {
	double		x;
	double		y;
}				t_sprite;

typedef struct	s_pair {
	double		dist;
	int			order;
}				t_pair;

typedef struct	s_sp_data {
	t_sprite	*spr_arr;
	int			num_sp;
	double		*z_buffer;
	int			*sp_order;
	double		*sp_dist;
	t_sprite	cur_sp;
	double		inv_det;
	t_vector	transform;
	int			sp_screen_x;
	int			sp_height;
	int			sp_width;
	t_point		draw_start;
	t_point		draw_end;
	t_point		tex;
	int			d;
	size_t		color;
	t_pair		*pair;
}				t_sp_data;

typedef struct	s_data {
	t_mlx		mlx;
	t_pl		pl;
	t_map_data	map_data;
	t_algo_data	algo_data;
	t_key		key;
	t_txtr_data	txtr_data;
	t_sp_data	sp_data;
}				t_data;

void			init_data(t_data *data);
void			init_pl(t_pl *pl);
void			init_map_data(t_map_data *map_data);
void			init_mlx(t_mlx *mlx);
void			init_algo_data(t_algo_data *algo_data);

void			init_key(t_key *key);
void			init_txtr_data(t_txtr_data *txtr_data);
void			init_sp_data(t_sp_data *sp_data);
void			init_sprites(t_data *data);
void			init_textures(t_data *data);

void			validate_texture(char *texture);
void			validate_r(int resolution, t_data *data);
void			validate_color(int color);

int				check_for_r(char *line, t_data *data);
int				check_for_no(char *line, t_data *data);
int				check_for_so(char *line, t_data *data);
int				check_for_we(char *line, t_data *data);
int				check_for_ea(char *line, t_data *data);

int				check_for_s(char *line, t_data *data);
int				check_for_f(char *line, t_data *data);
int				check_for_c(char *line, t_data *data);

void			key_w_or_key_s(t_data *data, double movespeed);
void			key_a_or_key_d(t_data *data, double movespeed);
void			key_left_or_key_right(t_key key,
				t_pl *pl, t_algo_data algo_data, double rotspeed);
int				key_pressed(int key, t_data *data);
int				key_released(int key, t_data *data);

void			sort_sprites(t_sp_data *sp_data);
void			quick_sort(t_pair *arr, int start, int stop);
int				partition(t_pair *arr, int start, int stop);

int				move(t_data *data);
void			draw_fl_and_ce(t_color fl, t_color ce, t_data *data);
void			cast_rays(t_data *data);
void			cast_sprites(t_data *data);

void			def_texture(t_data *data);
void			cr_part1(t_data *data, int x);
void			cr_part2(t_data *data);
void			cr_part3(t_data *data);

void			cr_part4(t_data *data);
void			cr_part5(t_data *data);
void			cr_part6(t_data *data, int x);

void			cs_part1(t_data *data, int sp_coun);
void			cs_part2(t_data *data, int sp_coun);
void			cs_part3(t_data *data);
void			cs_part4(t_data *data, int stripe, int y);

void			parse_params(t_data *data, char *argv);
void			parse_map(t_data *data);

void			find_pl_and_cn_spr(t_data *data, t_map_data map_data);
char			**make_map(t_list **head, int size, t_data *data);

void			init_parse_start(t_data *data, char *argv1);
void			mlx_loops_and_hooks(t_data *data);
int				all_hook(t_data *data);
int				simple_exit(void);

int				create_trgb(int t, int r, int g, int b);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			start_mlx(t_data *data);

void			make_screenshot(t_data *data, char *name);
void			make_screenshot_good_bye(t_data *data, char *name);

void			validate_map(t_data *data);
void			check_for_invalid(t_map_data *map_data, int i, int j);
void			check_for_space_extra(t_map_data *map_data,
				int i, int j, int error);

void			check_adit_color(char *line, int k);
void			check_adit_res(char *line, int k);
void			memory_error(void);
void			lacking_parametrs_error(void);
int				get_color(t_data *data, int x, int y);

void			lacking_color_error(void);
int				check_for_f_extra2(char *line, t_data *data, int k);
int				check_for_c_extra2(char *line, t_data *data, int k);

#endif
