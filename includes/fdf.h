/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/26 19:20:18 by cochatel         ###   ########.fr       */
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

// EVENTS

# define ESC 65307
# define RIGHT_CLICK 3
# define LEFT_CLICK 1
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define KEY_1 49
# define KEY_2 50
# define KEY_3 51
# define KEY_4 52

// COLORS

# define MENU_BACKGD -10854805 
# define WIN_BACKGD 
# define MENU_LIMIT -657956 //7181017
# define TEXT_COLOR -657956 
# define TITLE_COLOR -178650

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
	t_color			max_color;
	t_color			min_color;
	enum e_mode		color_mode;
}	t_map;

typedef struct s_camera
{
	double	x_angle;
	double	y_angle;
	double	z_angle;
	int		zoom;
	t_point	mouse_click;
	t_point	mouse_move;
	int		view_mode;
}	t_camera;

typedef struct s_event
{
	bool	is_left_pressed;
	bool	is_right_pressed;
	bool	is_1_pressed;
	bool	is_2_pressed;
	bool	is_3_pressed;
	bool	is_4_pressed;
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

// Utils
t_point	new_map_center(t_vars *vars);
void	put_str(t_vars *vars, t_point coord, int color, char *text);
void	put_pixel_menu(int x, int y, t_data_img *img, int color);

// Map
char	*get_full_line(int fd, int is_eof, t_vars *vars);
void	get_map(char *argv[], t_vars *vars);

// Geometry
void	center(t_point *point, t_point map_center);
void	scale(t_point *point, t_camera camera);
void	isometric_projection(t_point *point, t_camera camera);
void	apply_changes_and_draw(t_point origin, t_point dest, t_vars *vars);
void	transpose(t_point *point, t_camera camera);
void	rotate(t_vars *vars);

// Rendering
void	put_pixel(int x, int y, t_data_img *img, int color);
void	draw_line(t_point origin, t_point dest, t_vars *vars);
void	event_manager(t_vars *vars);
void	render_window(t_vars *vars);

// Init
void	ft_mlx_init(t_vars *vars);
void	init_camera(t_camera *camera);
void	init_event(t_event *event);
void	init_map(t_vars *vars);

// Events
int		mouse_wheel(int mouse_code, t_vars *vars);
int		mouse_click(int mouse_code, int x, int y, t_vars *vars);
int		mouse_released(int mouse_code, int x, int y, t_vars *vars);
int		mouse_pressed(int mouse_code, int x, int y, t_vars *vars);
int		mouse_move(int x, int y, t_vars *vars);
int		key_pressed(int keycode, t_vars *vars);
int		key_released(int keycode, t_vars *vars);

// Color
void	set_point_color(t_point *point, t_vars *vars);
int		find_color(int max_color, int min_color, t_vars *vars, int height);
int		set_pix_color(t_point origin, t_point dest, t_point pix, t_vars *vars);

//Color Utils
void	put_color_mode(enum e_mode color_mode, t_vars *vars);
int		create_color(int t, int r, int g, int b);
float	fraction(float x1, float x2, float x);

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

int my_close(t_vars *vars);

#endif
