/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/03/08 16:24:34 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line_bonus.h"
# include "../libft/includes/ft_printf_bonus.h"
# include <math.h>
# include <stdlib.h>
# include <limits.h>

# define MENU_WIDTH 250
# define MENU_HEIGHT 900
# define WIN_WIDTH 1200
# define WIN_HEIGHT 900
# define MOUSE_SENSITIVITY 0.0025
# define VERY_LOW -50
# define LOW 2
# define MIDDLE 125
# define HIGHT 200
# define VERY_HIGHT 250

// EVENTS

# define ESC 65307
# define LEFT_CLICK 1
# define WHEEL 2
# define RIGHT_CLICK 3
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define KEY_1 49
# define KEY_2 50
# define KEY_3 51
# define KEY_4 52
# define SPACE 32
# define W 119
# define S 115
# define A 97
# define D 100
# define E 101
# define Q 113
# define T 116
# define C 99
# define TAB 65289

// COLORS

# define MENU_BACKGD -10854805 
# define WIN_BACKGD 
# define MENU_LIMIT -657956 //7181017
# define TEXT_COLOR -657956 
# define TITLE_COLOR -175680

///////////////////
//|	Structures	|//
///////////////////

enum e_mode
{
	TERRAIN,
	WHITE_TO_RED,
	BLUE_TO_ORANGE,
	WHITE
};

typedef struct s_color
{
	int	t;
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	t_color	color;
}			t_point;

typedef struct s_data_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		frame_count;	
}	t_data_img;

typedef struct s_map
{
	int				**map;
	int				x_axis;
	int				y_axis;
	int				z_max;
	int				z_min;
	t_color			very_low_color;
	t_color			low_color;
	t_color			mid_color;
	t_color			hight_color;
	t_color			very_hight_color;
	enum e_mode		color_mode;
}	t_map;

typedef struct s_camera
{
	double	x_angle;
	double	y_angle;
	double	z_angle;
	int		zoom;
	int		view_mode;
	t_point	mouse_click;
	t_point	mouse_move;
	t_point	mouse_r_click;
	t_point	mouse_r_move;
	t_point	tot_offset;
}	t_camera;

typedef struct s_event
{
	bool	is_left_pressed;
	bool	is_right_pressed;
	bool	is_1_pressed;
	bool	is_2_pressed;
	bool	is_3_pressed;
	bool	is_4_pressed;
	bool	has_mouse_moved;
	bool	is_rotated;
	bool	is_transposed;
	bool	is_terrain;
}	t_event;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_camera	camera;
	t_map		map;
	t_data_img	img;
	t_event		event;

}	t_vars;

///////////////////
//|	Functions	|//
///////////////////

// Error
void	exit_error(char *msg, int error);
void	free_error(t_vars *vars, char *msg, int error);
void	error_map(char *str1, char *str2, t_vars *vars, char *msg);
void	free_mlx(t_vars *vars);

// Utils
void	put_str(t_vars *vars, t_point coord, int color, char *text);
void	put_pixel_menu(int x, int y, t_data_img *img, int color);
void	draw_square(t_vars *vars, t_point width, t_point height, int color);
void	select_view_mode(t_camera *camera);
void	select_gradient_mode(int keycode, t_event *event);
t_point	new_map_center(t_vars *vars);

// Map
void	get_map(char *argv[], t_vars *vars);
void	find_min_max_z(t_map *map);
char	*get_full_line(int fd, int is_eof, t_vars *vars);
int		map_lengths(char **map, int *rows, int *cols);
int		get_matrix(t_vars *vars, int ***new_map, char **map);

// Geometry
void	center(t_point *point);
void	scale(t_point *point, t_camera camera);
void	isometric_projection(t_point *point);
void	oblic_projection(t_point *point);
void	apply_changes_and_draw(t_point origin, t_point dest, t_vars *vars);
void	transpose(t_point *point, t_camera *camera, t_event event);
void	get_angles(t_camera *camera);
void	rotate_x(t_point *point, t_camera camera);
void	rotate_y(t_point *point, t_camera camera);
void	rotate_z(t_point *point, t_camera camera);

// Rendering
void	event_manager(t_vars *vars);
void	render_window(t_vars *vars);
void	put_pixel(int x, int y, t_data_img *img, int color);
void	draw_line(t_point origin, t_point dest, t_vars *vars);
void	hori_slope(t_point origin, t_point dest, t_vars *vars, t_point diff);
void	verti_slope(t_point origin, t_point dest, t_vars *vars, t_point diff);

// Init
void	ft_mlx_init(t_vars *vars);
void	init_camera(t_camera *camera);
void	init_event(t_event *event);
void	init_map(t_vars *vars);

// Events
int		my_close(t_vars *vars);
int		mouse_wheel(int mouse_code, t_vars *vars);
int		mouse_click(int mouse_code, int x, int y, t_vars *vars);
int		mouse_released(int mouse_code, int x, int y, t_vars *vars);
int		mouse_pressed(int mouse_code, int x, int y, t_vars *vars);
int		mouse_move(int x, int y, t_vars *vars);
int		key_pressed(int keycode, t_vars *vars);
int		key_released(int keycode, t_vars *vars);

// Color
void	gradient_color_mode(t_point *point, t_map *map);
void	gradient_terrain_mode(t_point *point, t_map *map);
int		find_color(int max_color, int min_color, t_point point, int height);
int		set_pix_color(t_point origin, t_point dest, t_point pix);

//Color Utils
void	put_color_mode(enum e_mode color_mode, t_vars *vars);
int		create_color(int t, int r, int g, int b);
float	fraction(float x1, float x2, float x);
void	inbetween_col(t_point *pt, t_color max_col, t_color min_col, t_point z);
void	put_main_colors(t_point *point, t_color color);

// Mode
void	white(t_vars *vars);
void	white_to_red(t_vars *vars);
void	blue_to_orange(t_vars *vars);
void	terrain(t_vars *vars);

// Menu
void	draw_menu(t_vars *vars);
void	draw_background(t_vars *vars);
void	color_mode_str(t_vars *vars);
void	view_mode_str(t_vars *vars);
void	map_info_str(t_vars *vars, t_point coord, int tmp);

#endif
